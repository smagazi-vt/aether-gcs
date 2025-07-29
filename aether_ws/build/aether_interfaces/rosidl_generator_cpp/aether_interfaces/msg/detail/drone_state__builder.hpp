// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/msg/detail/drone_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace msg
{

namespace builder
{

class Init_DroneState_is_connected
{
public:
  explicit Init_DroneState_is_connected(::aether_interfaces::msg::DroneState & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::msg::DroneState is_connected(::aether_interfaces::msg::DroneState::_is_connected_type arg)
  {
    msg_.is_connected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::msg::DroneState msg_;
};

class Init_DroneState_is_armed
{
public:
  explicit Init_DroneState_is_armed(::aether_interfaces::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_is_connected is_armed(::aether_interfaces::msg::DroneState::_is_armed_type arg)
  {
    msg_.is_armed = std::move(arg);
    return Init_DroneState_is_connected(msg_);
  }

private:
  ::aether_interfaces::msg::DroneState msg_;
};

class Init_DroneState_flight_mode
{
public:
  explicit Init_DroneState_flight_mode(::aether_interfaces::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_is_armed flight_mode(::aether_interfaces::msg::DroneState::_flight_mode_type arg)
  {
    msg_.flight_mode = std::move(arg);
    return Init_DroneState_is_armed(msg_);
  }

private:
  ::aether_interfaces::msg::DroneState msg_;
};

class Init_DroneState_firmware_type
{
public:
  explicit Init_DroneState_firmware_type(::aether_interfaces::msg::DroneState & msg)
  : msg_(msg)
  {}
  Init_DroneState_flight_mode firmware_type(::aether_interfaces::msg::DroneState::_firmware_type_type arg)
  {
    msg_.firmware_type = std::move(arg);
    return Init_DroneState_flight_mode(msg_);
  }

private:
  ::aether_interfaces::msg::DroneState msg_;
};

class Init_DroneState_system_id
{
public:
  Init_DroneState_system_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneState_firmware_type system_id(::aether_interfaces::msg::DroneState::_system_id_type arg)
  {
    msg_.system_id = std::move(arg);
    return Init_DroneState_firmware_type(msg_);
  }

private:
  ::aether_interfaces::msg::DroneState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::msg::DroneState>()
{
  return aether_interfaces::msg::builder::Init_DroneState_system_id();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__BUILDER_HPP_
