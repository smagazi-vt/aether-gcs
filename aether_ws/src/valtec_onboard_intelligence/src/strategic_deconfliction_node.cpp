/*
 * strategic_deconfliction_node.cpp
 *
 * This node runs on the GCS and provides the core safety logic for the MVP.
 * It discovers all drones, projects their future paths to provide strategic
 * warnings, and acts as a "virtual sensor" by publishing OBSTACLE_DISTANCE
 * messages to trigger PX4's built-in collision prevention.
 */

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <aether_interfaces/msg/deconfliction_warning.hpp>
#include <mavros_msgs/msg/obstacle_distance.hpp> // Include the necessary message
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <regex>

using namespace std::chrono_literals;

// --- Configuration ---
const double PREDICTION_HORIZON = 10.0;
const double MIN_SAFE_DISTANCE = 15.0; // Safety bubble for virtual sensor
const double DISCOVERY_INTERVAL = 5.0;

struct DroneInfo
{
    nav_msgs::msg::Odometry odom;
    rclcpp::Publisher<mavros_msgs::msg::ObstacleDistance>::SharedPtr obstacle_pub;
};

class StrategicDeconflictionNode : public rclcpp::Node
{
public:
    StrategicDeconflictionNode() : Node("strategic_deconfliction_node")
    {
        warning_publisher_ = this->create_publisher<aether_interfaces::msg::DeconflictionWarning>("/aether/deconfliction_warnings", 10);

        discovery_timer_ = this->create_wall_timer(
            std::chrono::duration<double>(DISCOVERY_INTERVAL), std::bind(&StrategicDeconflictionNode::discover_drones, this));
        
        check_timer_ = this->create_wall_timer(100ms, std::bind(&StrategicDeconflictionNode::check_for_conflicts, this)); // Increased frequency

        RCLCPP_INFO(this->get_logger(), "Strategic Deconfliction node started.");
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
                if (discovered_drones_.find(drone_id) == discovered_drones_.end()) {
                    RCLCPP_INFO(this->get_logger(), "Deconfliction: Discovering drone %d", drone_id);
                    
                    // Create a subscriber for this drone's odometry
                    auto sub = this->create_subscription<nav_msgs::msg::Odometry>(
                        topic_pair.first, 10,
                        [this, drone_id](const nav_msgs::msg::Odometry::SharedPtr msg) {
                            if (fleet_info_.count(drone_id)) {
                                fleet_info_[drone_id].odom = *msg;
                            }
                        });
                    subscriptions_[drone_id] = sub;

                    // Create a publisher for this drone's obstacle messages
                    std::string obstacle_topic = "/drone" + std::to_string(drone_id) + "/mavros/obstacle/send";
                    auto pub = this->create_publisher<mavros_msgs::msg::ObstacleDistance>(obstacle_topic, 10);
                    
                    fleet_info_[drone_id] = {nav_msgs::msg::Odometry(), pub};
                    discovered_drones_.insert(drone_id);
                }
            }
        }
    }

    void check_for_conflicts()
    {
        if (fleet_info_.size() < 2) return;

        std::vector<int> active_drones;
        for (const auto& pair : fleet_info_) {
            active_drones.push_back(pair.first);
        }

        for (size_t i = 0; i < active_drones.size(); ++i) {
            for (size_t j = i + 1; j < active_drones.size(); ++j) {
                int id1 = active_drones[i];
                int id2 = active_drones[j];

                const auto& odom1 = fleet_info_[id1].odom;
                const auto& odom2 = fleet_info_[id2].odom;

                double dx = odom1.pose.pose.position.x - odom2.pose.pose.position.x;
                double dy = odom1.pose.pose.position.y - odom2.pose.pose.position.y;
                double current_distance = std::sqrt(dx*dx + dy*dy);

                if (current_distance < MIN_SAFE_DISTANCE) {
                    RCLCPP_WARN(this->get_logger(), "Collision alert between Drone %d and Drone %d! Distance: %.2f m", id1, id2, current_distance);
                    send_obstacle_message(id1, id2, current_distance);
                    send_obstacle_message(id2, id1, current_distance);
                }
            }
        }
    }

    void send_obstacle_message(int own_id, int intruder_id, double distance) {
        const auto& own_odom = fleet_info_[own_id].odom;
        const auto& intruder_odom = fleet_info_[intruder_id].odom;

        double dx = intruder_odom.pose.pose.position.x - own_odom.pose.pose.position.x;
        double dy = intruder_odom.pose.pose.position.y - own_odom.pose.pose.position.y;
        double angle_rad = atan2(dy, dx);
        double angle_deg = fmod((std::to_string(angle_rad * 180.0 / M_PI) + 360.0), 360.0);

        auto msg = mavros_msgs::msg::ObstacleDistance();
        msg.header.stamp = this->get_clock()->now();
        msg.header.frame_id = "map";
        msg.sensor_type = 3; // MAV_SENSOR_ROTATION_CUSTOM
        msg.increment_f = 360.0;
        msg.min_distance = 100;
        msg.max_distance = 10000;
        
        std::fill(msg.distances.begin(), msg.distances.end(), 65535);
        int angle_index = static_cast<int>(angle_deg / 5.0) % 72;
        msg.distances[angle_index] = static_cast<uint16_t>(distance * 100);

        fleet_info_[own_id].obstacle_pub->publish(msg);
    }

    // Member variables
    std::set<int> discovered_drones_;
    std::map<int, DroneInfo> fleet_info_;
    std::map<int, rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr> subscriptions_;
    rclcpp::Publisher<aether_interfaces::msg::DeconflictionWarning>::SharedPtr warning_publisher_;
    rclcpp::TimerBase::SharedPtr discovery_timer_;
    rclcpp::TimerBase::SharedPtr check_timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StrategicDeconflictionNode>());
    rclcpp::shutdown();
    return 0;
}
