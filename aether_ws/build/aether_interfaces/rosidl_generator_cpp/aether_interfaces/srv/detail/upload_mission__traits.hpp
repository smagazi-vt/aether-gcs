// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from aether_interfaces:srv/UploadMission.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__TRAITS_HPP_
#define AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "aether_interfaces/srv/detail/upload_mission__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace aether_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const UploadMission_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: file_path
  {
    out << "file_path: ";
    rosidl_generator_traits::value_to_yaml(msg.file_path, out);
    out << ", ";
  }

  // member: target_system_id
  {
    out << "target_system_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_system_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UploadMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: file_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "file_path: ";
    rosidl_generator_traits::value_to_yaml(msg.file_path, out);
    out << "\n";
  }

  // member: target_system_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_system_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_system_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UploadMission_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace aether_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aether_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aether_interfaces::srv::UploadMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::srv::UploadMission_Request & msg)
{
  return aether_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::srv::UploadMission_Request>()
{
  return "aether_interfaces::srv::UploadMission_Request";
}

template<>
inline const char * name<aether_interfaces::srv::UploadMission_Request>()
{
  return "aether_interfaces/srv/UploadMission_Request";
}

template<>
struct has_fixed_size<aether_interfaces::srv::UploadMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::srv::UploadMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::srv::UploadMission_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace aether_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const UploadMission_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UploadMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UploadMission_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace aether_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use aether_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const aether_interfaces::srv::UploadMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  aether_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use aether_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const aether_interfaces::srv::UploadMission_Response & msg)
{
  return aether_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<aether_interfaces::srv::UploadMission_Response>()
{
  return "aether_interfaces::srv::UploadMission_Response";
}

template<>
inline const char * name<aether_interfaces::srv::UploadMission_Response>()
{
  return "aether_interfaces/srv/UploadMission_Response";
}

template<>
struct has_fixed_size<aether_interfaces::srv::UploadMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<aether_interfaces::srv::UploadMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<aether_interfaces::srv::UploadMission_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<aether_interfaces::srv::UploadMission>()
{
  return "aether_interfaces::srv::UploadMission";
}

template<>
inline const char * name<aether_interfaces::srv::UploadMission>()
{
  return "aether_interfaces/srv/UploadMission";
}

template<>
struct has_fixed_size<aether_interfaces::srv::UploadMission>
  : std::integral_constant<
    bool,
    has_fixed_size<aether_interfaces::srv::UploadMission_Request>::value &&
    has_fixed_size<aether_interfaces::srv::UploadMission_Response>::value
  >
{
};

template<>
struct has_bounded_size<aether_interfaces::srv::UploadMission>
  : std::integral_constant<
    bool,
    has_bounded_size<aether_interfaces::srv::UploadMission_Request>::value &&
    has_bounded_size<aether_interfaces::srv::UploadMission_Response>::value
  >
{
};

template<>
struct is_service<aether_interfaces::srv::UploadMission>
  : std::true_type
{
};

template<>
struct is_service_request<aether_interfaces::srv::UploadMission_Request>
  : std::true_type
{
};

template<>
struct is_service_response<aether_interfaces::srv::UploadMission_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__TRAITS_HPP_
