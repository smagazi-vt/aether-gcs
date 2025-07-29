cmake_minimum_required(VERSION 3.8)
project(aether_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# --- THIS IS THE CRITICAL FIX ---
# We must explicitly find the std_msgs package so that CMake knows where
# to find the header files (like header__struct.h) that our custom
# FleetState.msg depends on.
find_package(std_msgs REQUIRED)

# This is the command that generates your custom service and message code.
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/UploadMission.srv"
  "msg/DroneState.msg"
  "msg/FleetState.msg"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# This command finalizes the package and MUST be the last command.
ament_package()
