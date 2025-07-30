// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__TRAITS_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aether_interfaces/msg/detail/drone_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aether_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DroneState & msg,
  std::ostream & out)
{
  out << "{";
  // member: system_id
  {
    out << "system_id: ";
    rosidl_generator_traits::value_to_yaml(msg.system_id, out);
    out << ", ";
  }

  // member: firmware_type
  {
    out << "firmware_type: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_type, out);
    out << ", ";
  }

  // member: flight_mode
  {
    out << "flight_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.flight_mode, out);
    out << ", ";
  }

  // member: is_armed
  {
    out << "is_armed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_armed, out);
    out << ", ";
  }

  // member: is_connected
  {
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: system_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "system_id: ";
    rosidl_generator_traits::value_to_yaml(msg.system_id, out);
    out << "\n";
  }

  // member: firmware_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firmware_type: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_type, out);
    out << "\n";
  }

  // member: flight_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flight_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.flight_mode, out);
    out << "\n";
  }

  // member: is_armed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_armed: ";
    rosidl_generator_traits::value_to_yaml(msg.is_armed, out);
    out << "\n";
  }

  // member: is_connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_connected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace aether_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aether_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aether_interfaces::msg::DroneState & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::msg::DroneState & msg)
{
  return aether_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::msg::DroneState>()
{
  return "aether_interfaces::msg::DroneState";
}

template<>
inline const char * name<aether_interfaces::msg::DroneState>()
{
  return "aether_interfaces/msg/DroneState";
}

template<>
struct has_fixed_size<aether_interfaces::msg::DroneState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::msg::DroneState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::msg::DroneState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__TRAITS_HPP_
