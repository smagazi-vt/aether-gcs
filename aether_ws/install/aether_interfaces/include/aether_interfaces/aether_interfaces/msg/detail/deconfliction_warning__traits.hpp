// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__TRAITS_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aether_interfaces/msg/detail/deconfliction_warning__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace aether_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DeconflictionWarning & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: drone_id_1
  {
    out << "drone_id_1: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id_1, out);
    out << ", ";
  }

  // member: drone_id_2
  {
    out << "drone_id_2: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id_2, out);
    out << ", ";
  }

  // member: warning_text
  {
    out << "warning_text: ";
    rosidl_generator_traits::value_to_yaml(msg.warning_text, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeconflictionWarning & msg,
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

  // member: drone_id_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id_1: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id_1, out);
    out << "\n";
  }

  // member: drone_id_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id_2: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id_2, out);
    out << "\n";
  }

  // member: warning_text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "warning_text: ";
    rosidl_generator_traits::value_to_yaml(msg.warning_text, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeconflictionWarning & msg, bool use_flow_style = false)
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
  const aether_interfaces::msg::DeconflictionWarning & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::msg::DeconflictionWarning & msg)
{
  return aether_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::msg::DeconflictionWarning>()
{
  return "aether_interfaces::msg::DeconflictionWarning";
}

template<>
inline const char * name<aether_interfaces::msg::DeconflictionWarning>()
{
  return "aether_interfaces/msg/DeconflictionWarning";
}

template<>
struct has_fixed_size<aether_interfaces::msg::DeconflictionWarning>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::msg::DeconflictionWarning>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::msg::DeconflictionWarning>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__TRAITS_HPP_
