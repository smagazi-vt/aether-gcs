cmake_minimum_required(VERSION 3.8)
project(aether_gcs_logic_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(aether_interfaces REQUIRED)
find_package(nav_msgs REQUIRED)

add_executable(
  strategic_deconfliction_node
  src/strategic_deconfliction_node.cpp
)

ament_target_dependencies(
  strategic_deconfliction_node
  "rclcpp"
  "aether_interfaces"
  "nav_msgs"
)

install(TARGETS
  strategic_deconfliction_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()