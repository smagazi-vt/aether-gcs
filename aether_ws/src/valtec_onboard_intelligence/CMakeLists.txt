cmake_minimum_required(VERSION 3.8)
project(valtec_onboard_intelligence)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find all necessary ROS 2 package dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# --- THIS IS THE CRITICAL FIX ---
# The source file name has been changed to match your existing file.
add_executable(
  collision_avoider_node
  src/collision_avoider_node.cpp
)

# Link the executable against all the libraries it uses
ament_target_dependencies(
  collision_avoider_node
  "rclcpp"
  "geometry_msgs"
  "mavros_msgs"
  "nav_msgs"
  "tf2_ros"
)

# Install the executable so ros2 run and ros2 launch can find it
install(TARGETS
  collision_avoider_node
  DESTINATION lib/${PROJECT_NAME}
)

# Add launch file installation
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
