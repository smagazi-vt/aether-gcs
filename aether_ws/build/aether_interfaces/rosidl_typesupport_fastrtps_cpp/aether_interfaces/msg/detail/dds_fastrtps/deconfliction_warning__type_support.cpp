// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/deconfliction_warning__rosidl_typesupport_fastrtps_cpp.hpp"
#include "aether_interfaces/msg/detail/deconfliction_warning__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace aether_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
cdr_serialize(
  const aether_interfaces::msg::DeconflictionWarning & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: drone_id_1
  cdr << ros_message.drone_id_1;
  // Member: drone_id_2
  cdr << ros_message.drone_id_2;
  // Member: warning_text
  cdr << ros_message.warning_text;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  aether_interfaces::msg::DeconflictionWarning & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: drone_id_1
  cdr >> ros_message.drone_id_1;

  // Member: drone_id_2
  cdr >> ros_message.drone_id_2;

  // Member: warning_text
  cdr >> ros_message.warning_text;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
get_serialized_size(
  const aether_interfaces::msg::DeconflictionWarning & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: drone_id_1
  {
    size_t item_size = sizeof(ros_message.drone_id_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: drone_id_2
  {
    size_t item_size = sizeof(ros_message.drone_id_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: warning_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.warning_text.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
max_serialized_size_DeconflictionWarning(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: drone_id_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: drone_id_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: warning_text
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = aether_interfaces::msg::DeconflictionWarning;
    is_plain =
      (
      offsetof(DataType, warning_text) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DeconflictionWarning__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const aether_interfaces::msg::DeconflictionWarning *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DeconflictionWarning__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<aether_interfaces::msg::DeconflictionWarning *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DeconflictionWarning__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const aether_interfaces::msg::DeconflictionWarning *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DeconflictionWarning__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DeconflictionWarning(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DeconflictionWarning__callbacks = {
  "aether_interfaces::msg",
  "DeconflictionWarning",
  _DeconflictionWarning__cdr_serialize,
  _DeconflictionWarning__cdr_deserialize,
  _DeconflictionWarning__get_serialized_size,
  _DeconflictionWarning__max_serialized_size
};

static rosidl_message_type_support_t _DeconflictionWarning__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DeconflictionWarning__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace aether_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_aether_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<aether_interfaces::msg::DeconflictionWarning>()
{
  return &aether_interfaces::msg::typesupport_fastrtps_cpp::_DeconflictionWarning__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, aether_interfaces, msg, DeconflictionWarning)() {
  return &aether_interfaces::msg::typesupport_fastrtps_cpp::_DeconflictionWarning__handle;
}

#ifdef __cplusplus
}
#endif
