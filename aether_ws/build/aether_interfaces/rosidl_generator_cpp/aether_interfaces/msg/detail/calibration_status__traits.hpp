// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__TRAITS_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aether_interfaces/msg/detail/calibration_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aether_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CalibrationStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: system_id
  {
    out << "system_id: ";
    rosidl_generator_traits::value_to_yaml(msg.system_id, out);
    out << ", ";
  }

  // member: instruction_text
  {
    out << "instruction_text: ";
    rosidl_generator_traits::value_to_yaml(msg.instruction_text, out);
    out << ", ";
  }

  // member: progress_percentage
  {
    out << "progress_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.progress_percentage, out);
    out << ", ";
  }

  // member: is_complete
  {
    out << "is_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.is_complete, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalibrationStatus & msg,
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

  // member: instruction_text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "instruction_text: ";
    rosidl_generator_traits::value_to_yaml(msg.instruction_text, out);
    out << "\n";
  }

  // member: progress_percentage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress_percentage: ";
    rosidl_generator_traits::value_to_yaml(msg.progress_percentage, out);
    out << "\n";
  }

  // member: is_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.is_complete, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalibrationStatus & msg, bool use_flow_style = false)
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
  const aether_interfaces::msg::CalibrationStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::msg::CalibrationStatus & msg)
{
  return aether_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::msg::CalibrationStatus>()
{
  return "aether_interfaces::msg::CalibrationStatus";
}

template<>
inline const char * name<aether_interfaces::msg::CalibrationStatus>()
{
  return "aether_interfaces/msg/CalibrationStatus";
}

template<>
struct has_fixed_size<aether_interfaces::msg::CalibrationStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::msg::CalibrationStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::msg::CalibrationStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__TRAITS_HPP_
