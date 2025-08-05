/*
 * strategic_deconfliction_node.cpp
 *
 * This node runs on the GCS and provides high-level strategic deconfliction.
 * It projects the future paths of all drones and publishes a warning if
 * their paths are predicted to intersect.
 *
 * AUTHOR: Valtec
 * DATE: 2025-08-05
 */

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <aether_interfaces/msg/deconfliction_warning.hpp>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <regex>

// Using statements for brevity
using namespace std::chrono_literals;

// --- Configuration ---
const double PREDICTION_HORIZON = 10.0; // How many seconds into the future to predict
const double MIN_SAFE_DISTANCE = 20.0;  // Minimum allowed separation in meters
const double DISCOVERY_INTERVAL = 5.0;  // How often to scan for new drones

struct DroneInfo
{
    nav_msgs::msg::Odometry odom;
};

class StrategicDeconflictionNode : public rclcpp::Node
{
public:
    StrategicDeconflictionNode() : Node("strategic_deconfliction_node")
    {
        // Publisher for deconfliction warnings
        warning_publisher_ = this->create_publisher<aether_interfaces::msg::DeconflictionWarning>("/aether/deconfliction_warnings", 10);

        // Timers for discovery and checking
        discovery_timer_ = this->create_wall_timer(
            std::chrono::duration<double>(DISCOVERY_INTERVAL), std::bind(&StrategicDeconflictionNode::discover_drones, this));
        
        check_timer_ = this->create_wall_timer(1s, std::bind(&StrategicDeconflictionNode::check_for_conflicts, this));

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
                    auto sub = this->create_subscription<nav_msgs::msg::Odometry>(
                        topic_pair.first, 10,
                        [this, drone_id](const nav_msgs::msg::Odometry::SharedPtr msg) {
                            fleet_info_[drone_id].odom = *msg;
                        });
                    subscriptions_[drone_id] = sub;
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

                // Project future positions based on current velocity
                double future_x1 = odom1.pose.pose.position.x + odom1.twist.twist.linear.x * PREDICTION_HORIZON;
                double future_y1 = odom1.pose.pose.position.y + odom1.twist.twist.linear.y * PREDICTION_HORIZON;
                
                double future_x2 = odom2.pose.pose.position.x + odom2.twist.twist.linear.x * PREDICTION_HORIZON;
                double future_y2 = odom2.pose.pose.position.y + odom2.twist.twist.linear.y * PREDICTION_HORIZON;

                // Calculate the distance between the two predicted future points
                double dx = future_x1 - future_x2;
                double dy = future_y1 - future_y2;
                double future_distance = std::sqrt(dx*dx + dy*dy);

                if (future_distance < MIN_SAFE_DISTANCE) {
                    RCLCPP_WARN(this->get_logger(), "Strategic Conflict Detected between Drone %d and Drone %d!", id1, id2);
                    
                    auto warning_msg = aether_interfaces::msg::DeconflictionWarning();
                    warning_msg.header.stamp = this->get_clock()->now();
                    warning_msg.drone_id_1 = id1;
                    warning_msg.drone_id_2 = id2;
                    warning_msg.warning_text = "Projected flight paths conflict. Operator intervention may be required.";
                    warning_publisher_->publish(warning_msg);
                }
            }
        }
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
