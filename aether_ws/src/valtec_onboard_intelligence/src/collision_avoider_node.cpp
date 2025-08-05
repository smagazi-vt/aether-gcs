/*
 * onboard_collision_avoider.cpp
 *
 * This node runs on each drone's companion computer. It implements the
 * Velocity Obstacles (VO) algorithm for real-time, decentralized collision avoidance.
 *
 * AUTHOR: Valtec
 * DATE: 2025-08-05
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp> // A better source for position + velocity
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <regex>
#include <tf2/LinearMath/Vector3.h>
#include <tf2/LinearMath/Quaternion.h>

// Using statements for brevity
using namespace std::chrono_literals;

// --- Configuration ---
const double SAFETY_RADIUS = 10.0;     // Combined radius of two drones (m)
const double TIME_HORIZON = 5.0;       // How far in the future to predict (s)
const double DISCOVERY_INTERVAL = 5.0; // How often to scan for new drones (s)

struct DroneInfo
{
    nav_msgs::msg::Odometry odom;
    bool is_active = false;
};

class OnboardCollisionAvoider : public rclcpp::Node
{
public:
    OnboardCollisionAvoider() : Node("onboard_collision_avoider")
    {
        // Get this drone's own ID from a parameter passed by the launch file
        this->declare_parameter<int>("system_id", 0);
        this->own_id_ = this->get_parameter("system_id").as_int();

        if (this->own_id_ == 0) {
            RCLCPP_FATAL(this->get_logger(), "Parameter 'system_id' was not set! Shutting down.");
            rclcpp::shutdown();
            return;
        }

        // Publisher for velocity override commands
        std::string vel_topic = "/drone" + std::to_string(own_id_) + "/mavros/setpoint_velocity/cmd_vel_unstamped";
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::TwistStamped>(vel_topic, 10);

        // Subscriber to our own odometry (position + velocity)
        std::string own_odom_topic = "/drone" + std::to_string(own_id_) + "/mavros/global_position/local"; // Example topic
        own_odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            own_odom_topic, 10,
            [this](const nav_msgs::msg::Odometry::SharedPtr msg) {
                this->own_odom_ = *msg;
            });

        // Timer to periodically discover new drones
        discovery_timer_ = this->create_wall_timer(
            std::chrono::duration<double>(DISCOVERY_INTERVAL), std::bind(&OnboardCollisionAvoider::discover_drones, this));

        // Timer to run the main VO calculation loop
        vo_timer_ = this->create_wall_timer(100ms, std::bind(&OnboardCollisionAvoider::calculate_and_avoid, this));

        RCLCPP_INFO(this->get_logger(), "Onboard Collision Avoider for Drone %d started.", own_id_);
    }

private:
    void discover_drones()
    {
        auto topic_names_and_types = this->get_topic_names_and_types();
        std::regex odom_topic_regex(R"(/drone(\d+)/mavros/global_position/local)");

        for (const auto& topic_pair : topic_names_and_types) {
            std::smatch match;
            if (std::regex_match(topic_pair.first, match, odom_topic_regex)) {
                int drone_id = std::stoi(match[1].str());
                
                // Don't subscribe to our own topic
                if (drone_id == own_id_) continue;

                if (discovered_drones_.find(drone_id) == discovered_drones_.end()) {
                    RCLCPP_INFO(this->get_logger(), "Discovered neighbor drone: ID %d", drone_id);
                    auto sub = this->create_subscription<nav_msgs::msg::Odometry>(
                        topic_pair.first, 10,
                        [this, drone_id](const nav_msgs::msg::Odometry::SharedPtr msg) {
                            fleet_info_[drone_id].odom = *msg;
                            fleet_info_[drone_id].is_active = true;
                        });
                    subscriptions_[drone_id] = sub;
                    discovered_drones_.insert(drone_id);
                }
            }
        }
    }

    void calculate_and_avoid()
    {
        tf2::Vector3 own_pos(own_odom_.pose.pose.position.x, own_odom_.pose.pose.position.y, own_odom_.pose.pose.position.z);
        tf2::Vector3 own_vel(own_odom_.twist.twist.linear.x, own_odom_.twist.twist.linear.y, own_odom_.twist.twist.linear.z);

        // For this MVP, we assume the desired velocity is the current velocity.
        // FUTURE IMPROVEMENT: A MORE ADVANCED IMPLEMENTATION WOULD SUBSCRIBE TO THE
        // MISSION PLANNER'S DESIRED VELOCITY TOPIC.
        tf2::Vector3 desired_vel = own_vel;

        tf2::Vector3 avoidance_vel = desired_vel;

        for (auto const& [id, drone_info] : fleet_info_)
        {
            if (!drone_info.is_active) continue;

            tf2::Vector3 intruder_pos(drone_info.odom.pose.pose.position.x, drone_info.odom.pose.pose.position.y, drone_info.odom.pose.pose.position.z);
            tf2::Vector3 intruder_vel(drone_info.odom.twist.twist.linear.x, drone_info.odom.twist.twist.linear.y, drone_info.odom.twist.twist.linear.z);

            // --- CORE VELOCITY OBSTACLE LOGIC ---
            tf2::Vector3 relative_pos = intruder_pos - own_pos;
            tf2::Vector3 relative_vel = own_vel - intruder_vel;

            // Calculate the collision cone
            double dist_sq = relative_pos.length2();
            if (dist_sq > (SAFETY_RADIUS * TIME_HORIZON) * (SAFETY_RADIUS * TIME_HORIZON)) continue; // Too far to be a threat

            double apex_angle = asin(SAFETY_RADIUS / relative_pos.length());
            double center_angle = atan2(relative_pos.y(), relative_pos.x());

            // Check if our relative velocity is inside the collision cone
            double vel_angle = atan2(relative_vel.y(), relative_vel.x());
            
            if (std::abs(vel_angle - center_angle) < apex_angle)
            {
                RCLCPP_WARN(this->get_logger(), "Collision risk with Drone %d! Taking evasive action.", id);
                
                // --- ESCAPE MANEUVER LOGIC ---
                // This is a simple escape logic. It finds the "edge" of the cone
                // and sets the new velocity there.
                // FUTURE IMPROVEMENT: A MORE ROBUST IMPLEMENTATION (LIKE RVO or HRVO)
                // WOULD NEGOTIATE WITH THE OTHER DRONE.
                double escape_angle = center_angle + (vel_angle > center_angle ? apex_angle : -apex_angle);
                double vel_mag = relative_vel.length();

                tf2::Vector3 escape_vel_relative(cos(escape_angle) * vel_mag, sin(escape_angle) * vel_mag, relative_vel.z());
                
                // Convert back to absolute velocity
                avoidance_vel = escape_vel_relative + intruder_vel;
            }
        }

        // If the avoidance velocity is different from our desired velocity, publish the override.
        if (avoidance_vel.distance2(desired_vel) > 0.01) {
            publish_velocity_command(avoidance_vel);
        }
    }

    void publish_velocity_command(const tf2::Vector3& vel)
    {
        auto msg = std::make_unique<geometry_msgs::msg::TwistStamped>();
        msg->header.stamp = this->get_clock()->now();
        msg->header.frame_id = "map"; // Or appropriate frame
        msg->twist.linear.x = vel.x();
        msg->twist.linear.y = vel.y();
        msg->twist.linear.z = vel.z();
        velocity_publisher_->publish(std::move(msg));
    }

    // Member variables
    int own_id_;
    nav_msgs::msg::Odometry own_odom_;
    std::map<int, DroneInfo> fleet_info_;
    std::set<int> discovered_drones_;
    
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr velocity_publisher_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr own_odom_sub_;
    std::map<int, rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr> subscriptions_;
    
    rclcpp::TimerBase::SharedPtr discovery_timer_;
    rclcpp::TimerBase::SharedPtr vo_timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OnboardCollisionAvoider>());
    rclcpp::shutdown();
    return 0;
}
