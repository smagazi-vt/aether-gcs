// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__TRAITS_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aether_interfaces/msg/detail/fleet_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'drones'
#include "aether_interfaces/msg/detail/drone_state__traits.hpp"

namespace aether_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FleetState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: drones
  {
    if (msg.drones.size() == 0) {
      out << "drones: []";
    } else {
      out << "drones: [";
      size_t pending_items = msg.drones.size();
      for (auto item : msg.drones) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FleetState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: drones
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.drones.size() == 0) {
      out << "drones: []\n";
    } else {
      out << "drones:\n";
      for (auto item : msg.drones) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FleetState & msg, bool use_flow_style = false)
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
  const aether_interfaces::msg::FleetState & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::msg::FleetState & msg)
{
  return aether_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::msg::FleetState>()
{
  return "aether_interfaces::msg::FleetState";
}

template<>
inline const char * name<aether_interfaces::msg::FleetState>()
{
  return "aether_interfaces/msg/FleetState";
}

template<>
struct has_fixed_size<aether_interfaces::msg::FleetState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::msg::FleetState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::msg::FleetState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__TRAITS_HPP_
