// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/drone_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "aether_interfaces/msg/detail/drone_state__struct.hpp"

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

namespace aether_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
cdr_serialize(
  const aether_interfaces::msg::DroneState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: system_id
  cdr << ros_message.system_id;
  // Member: firmware_type
  cdr << ros_message.firmware_type;
  // Member: flight_mode
  cdr << ros_message.flight_mode;
  // Member: is_armed
  cdr << (ros_message.is_armed ? true : false);
  // Member: is_connected
  cdr << (ros_message.is_connected ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  aether_interfaces::msg::DroneState & ros_message)
{
  // Member: system_id
  cdr >> ros_message.system_id;

  // Member: firmware_type
  cdr >> ros_message.firmware_type;

  // Member: flight_mode
  cdr >> ros_message.flight_mode;

  // Member: is_armed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_armed = tmp ? true : false;
  }

  // Member: is_connected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_connected = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
get_serialized_size(
  const aether_interfaces::msg::DroneState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: system_id
  {
    size_t item_size = sizeof(ros_message.system_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: firmware_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.firmware_type.size() + 1);
  // Member: flight_mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.flight_mode.size() + 1);
  // Member: is_armed
  {
    size_t item_size = sizeof(ros_message.is_armed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_connected
  {
    size_t item_size = sizeof(ros_message.is_connected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_aether_interfaces
max_serialized_size_DroneState(
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


  // Member: system_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: firmware_type
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

  // Member: flight_mode
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

  // Member: is_armed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_connected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = aether_interfaces::msg::DroneState;
    is_plain =
      (
      offsetof(DataType, is_connected) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DroneState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const aether_interfaces::msg::DroneState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DroneState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<aether_interfaces::msg::DroneState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DroneState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const aether_interfaces::msg::DroneState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DroneState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DroneState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DroneState__callbacks = {
  "aether_interfaces::msg",
  "DroneState",
  _DroneState__cdr_serialize,
  _DroneState__cdr_deserialize,
  _DroneState__get_serialized_size,
  _DroneState__max_serialized_size
};

static rosidl_message_type_support_t _DroneState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DroneState__callbacks,
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
get_message_type_support_handle<aether_interfaces::msg::DroneState>()
{
  return &aether_interfaces::msg::typesupport_fastrtps_cpp::_DroneState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, aether_interfaces, msg, DroneState)() {
  return &aether_interfaces::msg::typesupport_fastrtps_cpp::_DroneState__handle;
}

#ifdef __cplusplus
}
#endif
