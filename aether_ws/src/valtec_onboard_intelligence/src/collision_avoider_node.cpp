/*
 * collision_avoider_node.cpp
 *
 * This node dynamically discovers drones by scanning for MAVROS topics.
 * It subscribes to the local position of each discovered drone.
 * If any two drones come within a specified minimum distance of each other,
 * it sends a command to one of them to enter "Hold" mode as a safety measure.
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <mavros_msgs/srv/command_long.hpp>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <regex>

// Using statements for brevity
using namespace std::chrono_literals;

// --- Configuration ---
const double MIN_SEPARATION_DISTANCE = 15.0; // Minimum safe distance in meters
const double DISCOVERY_INTERVAL = 5.0; // How often to scan for new drones in seconds

class CollisionAvoider : public rclcpp::Node
{
public:
    CollisionAvoider() : Node("collision_avoider_node")
    {
        // Timer to periodically check for collisions
        check_timer_ = this->create_wall_timer(
            500ms, std::bind(&CollisionAvoider::check_for_collisions, this));
            
        // Timer to periodically discover new drones
        discovery_timer_ = this->create_wall_timer(
            std::chrono::duration<double>(DISCOVERY_INTERVAL), std::bind(&CollisionAvoider::discover_drones, this));

        RCLCPP_INFO(this->get_logger(), "Collision Avoider node started. Discovering drones...");
    }

private:
    // Discovers new drones by scanning ROS 2 topics
    void discover_drones()
    {
        auto topic_names_and_types = this->get_topic_names_and_types();
        std::regex pose_topic_regex(R"(/mavros_(\d+)/local_position/pose)");
        
        for (const auto& topic_pair : topic_names_and_types) {
            std::smatch match;
            if (std::regex_match(topic_pair.first, match, pose_topic_regex)) {
                int drone_id = std::stoi(match[1].str());
                
                // If this is a new drone, set up subscribers and clients for it
                if (discovered_drones_.find(drone_id) == discovered_drones_.end()) {
                    RCLCPP_INFO(this->get_logger(), "Discovered new drone: ID %d", drone_id);
                    setup_drone(drone_id);
                    discovered_drones_.insert(drone_id);
                }
            }
        }
    }

    // Sets up the necessary subscribers and clients for a single drone
    void setup_drone(int drone_id)
    {
        // Subscriber to the drone's local position
        std::string pose_topic = "/mavros_" + std::to_string(drone_id) + "/local_position/pose";
        auto sub = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            pose_topic, 10, 
            [this, drone_id](const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
                // Store the latest position for the drone
                latest_positions_[drone_id] = *msg;
            });
        subscriptions_[drone_id] = sub;

        // Client to send MAVLink commands
        std::string service_name = "/mavros_" + std::to_string(drone_id) + "/cmd/command";
        auto client = this->create_client<mavros_msgs::srv::CommandLong>(service_name);
        command_clients_[drone_id] = client;
        
        RCLCPP_INFO(this->get_logger(), "Setup complete for Drone %d.", drone_id);
    }

    // Periodically checks the distances between all drones
    void check_for_collisions()
    {
        if (latest_positions_.size() < 2) {
            return;
        }

        std::vector<int> active_drones;
        for (const auto& pair : latest_positions_) {
            active_drones.push_back(pair.first);
        }

        for (size_t i = 0; i < active_drones.size(); ++i) {
            for (size_t j = i + 1; j < active_drones.size(); ++j) {
                int id1 = active_drones[i];
                int id2 = active_drones[j];

                const auto& pose1 = latest_positions_[id1].pose;
                const auto& pose2 = latest_positions_[id2].pose;

                double dx = pose1.position.x - pose2.position.x;
                double dy = pose1.position.y - pose2.position.y;
                double dz = pose1.position.z - pose2.position.z;
                double distance = std::sqrt(dx*dx + dy*dy + dz*dz);

                if (distance < MIN_SEPARATION_DISTANCE) {
                    RCLCPP_WARN(this->get_logger(), "Collision risk detected between Drone %d and Drone %d! Distance: %.2f m", id1, id2, distance);
                    command_hold_mode(std::max(id1, id2));
                }
            }
        }
    }

    // Sends a MAVLink command to put a drone into HOLD mode
    void command_hold_mode(int drone_id)
    {
        if (command_clients_.find(drone_id) == command_clients_.end()) {
            RCLCPP_ERROR(this->get_logger(), "No command client for Drone %d", drone_id);
            return;
        }

        auto client = command_clients_[drone_id];
        if (!client->service_is_ready()) {
            RCLCPP_WARN(this->get_logger(), "Command service for Drone %d not available.", drone_id);
            return;
        }

        auto request = std::make_shared<mavros_msgs::srv::CommandLong::Request>();
        request->command = 176; // MAV_CMD_DO_SET_MODE
        request->param1 = 1;     // MAV_MODE_FLAG_CUSTOM_MODE_ENABLED for PX4
        request->param2 = 4;     // Corresponds to PX4 Hold mode's base_mode (check PX4 docs)
        
        RCLCPP_INFO(this->get_logger(), "Sending HOLD command to Drone %d", drone_id);
        client->async_send_request(request);
    }

    // Member variables
    std::set<int> discovered_drones_;
    std::map<int, rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr> subscriptions_;
    std::map<int, geometry_msgs::msg::PoseStamped> latest_positions_;
    std::map<int, rclcpp::Client<mavros_msgs::srv::CommandLong>::SharedPtr> command_clients_;
    rclcpp::TimerBase::SharedPtr check_timer_;
    rclcpp::TimerBase::SharedPtr discovery_timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CollisionAvoider>());
    rclcpp::shutdown();
    return 0;
}