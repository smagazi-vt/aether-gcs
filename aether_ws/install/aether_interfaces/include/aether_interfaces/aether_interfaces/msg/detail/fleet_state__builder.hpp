// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__BUILDER_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/msg/detail/fleet_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace msg
{

namespace builder
{

class Init_FleetState_drones
{
public:
  explicit Init_FleetState_drones(::aether_interfaces::msg::FleetState & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::msg::FleetState drones(::aether_interfaces::msg::FleetState::_drones_type arg)
  {
    msg_.drones = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::msg::FleetState msg_;
};

class Init_FleetState_header
{
public:
  Init_FleetState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FleetState_drones header(::aether_interfaces::msg::FleetState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FleetState_drones(msg_);
  }

private:
  ::aether_interfaces::msg::FleetState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::msg::FleetState>()
{
  return aether_interfaces::msg::builder::Init_FleetState_header();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__BUILDER_HPP_
