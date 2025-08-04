// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:srv/StartCalibration.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__BUILDER_HPP_
#define AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/srv/detail/start_calibration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartCalibration_Request_sensor_type
{
public:
  explicit Init_StartCalibration_Request_sensor_type(::aether_interfaces::srv::StartCalibration_Request & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::srv::StartCalibration_Request sensor_type(::aether_interfaces::srv::StartCalibration_Request::_sensor_type_type arg)
  {
    msg_.sensor_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::srv::StartCalibration_Request msg_;
};

class Init_StartCalibration_Request_target_system_id
{
public:
  Init_StartCalibration_Request_target_system_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartCalibration_Request_sensor_type target_system_id(::aether_interfaces::srv::StartCalibration_Request::_target_system_id_type arg)
  {
    msg_.target_system_id = std::move(arg);
    return Init_StartCalibration_Request_sensor_type(msg_);
  }

private:
  ::aether_interfaces::srv::StartCalibration_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::srv::StartCalibration_Request>()
{
  return aether_interfaces::srv::builder::Init_StartCalibration_Request_target_system_id();
}

}  // namespace aether_interfaces


namespace aether_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartCalibration_Response_message
{
public:
  explicit Init_StartCalibration_Response_message(::aether_interfaces::srv::StartCalibration_Response & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::srv::StartCalibration_Response message(::aether_interfaces::srv::StartCalibration_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::srv::StartCalibration_Response msg_;
};

class Init_StartCalibration_Response_success
{
public:
  Init_StartCalibration_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartCalibration_Response_message success(::aether_interfaces::srv::StartCalibration_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_StartCalibration_Response_message(msg_);
  }

private:
  ::aether_interfaces::srv::StartCalibration_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::srv::StartCalibration_Response>()
{
  return aether_interfaces::srv::builder::Init_StartCalibration_Response_success();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__BUILDER_HPP_
