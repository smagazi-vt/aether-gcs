cmake_minimum_required(VERSION 3.8)
project(valtec_onboard_intelligence)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# Add the executable for your C++ node
add_executable(collision_avoider_node src/collision_avoider_node.cpp)

# Link the executable against the required libraries
ament_target_dependencies(collision_avoider_node
  "rclcpp"
  "geometry_msgs"
  "mavros_msgs"
  "nav_msgs"
  "tf2_ros"
)

# Install the executable so ros2 run can find it
install(TARGETS
  collision_avoider_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()