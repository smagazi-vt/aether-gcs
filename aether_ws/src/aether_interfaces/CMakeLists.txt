cmake_minimum_required(VERSION 3.8)
project(aether_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

# This is the command that generates your custom service and message code.
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/UploadMission.srv"
  "msg/DroneState.msg"
  "msg/FleetState.msg"
  "srv/StartCalibration.srv"
  "msg/CalibrationStatus.msg"
  "msg/DeconflictionWarning.msg"
  DEPENDENCIES std_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# This command finalizes the package and MUST be the last command.
ament_package()
