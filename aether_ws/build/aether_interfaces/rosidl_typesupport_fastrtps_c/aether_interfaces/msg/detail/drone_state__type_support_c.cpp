// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/drone_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "aether_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "aether_interfaces/msg/detail/drone_state__struct.h"
#include "aether_interfaces/msg/detail/drone_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // firmware_type, flight_mode
#include "rosidl_runtime_c/string_functions.h"  // firmware_type, flight_mode

// forward declare type support functions


using _DroneState__ros_msg_type = aether_interfaces__msg__DroneState;

static bool _DroneState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneState__ros_msg_type * ros_message = static_cast<const _DroneState__ros_msg_type *>(untyped_ros_message);
  // Field name: system_id
  {
    cdr << ros_message->system_id;
  }

  // Field name: firmware_type
  {
    const rosidl_runtime_c__String * str = &ros_message->firmware_type;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: flight_mode
  {
    const rosidl_runtime_c__String * str = &ros_message->flight_mode;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: is_armed
  {
    cdr << (ros_message->is_armed ? true : false);
  }

  // Field name: is_connected
  {
    cdr << (ros_message->is_connected ? true : false);
  }

  return true;
}

static bool _DroneState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneState__ros_msg_type * ros_message = static_cast<_DroneState__ros_msg_type *>(untyped_ros_message);
  // Field name: system_id
  {
    cdr >> ros_message->system_id;
  }

  // Field name: firmware_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->firmware_type.data) {
      rosidl_runtime_c__String__init(&ros_message->firmware_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->firmware_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'firmware_type'\n");
      return false;
    }
  }

  // Field name: flight_mode
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->flight_mode.data) {
      rosidl_runtime_c__String__init(&ros_message->flight_mode);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->flight_mode,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'flight_mode'\n");
      return false;
    }
  }

  // Field name: is_armed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_armed = tmp ? true : false;
  }

  // Field name: is_connected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_connected = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aether_interfaces
size_t get_serialized_size_aether_interfaces__msg__DroneState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneState__ros_msg_type * ros_message = static_cast<const _DroneState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name system_id
  {
    size_t item_size = sizeof(ros_message->system_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name firmware_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->firmware_type.size + 1);
  // field.name flight_mode
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->flight_mode.size + 1);
  // field.name is_armed
  {
    size_t item_size = sizeof(ros_message->is_armed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_connected
  {
    size_t item_size = sizeof(ros_message->is_connected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DroneState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_aether_interfaces__msg__DroneState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_aether_interfaces
size_t max_serialized_size_aether_interfaces__msg__DroneState(
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

  // member: system_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: firmware_type
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
  // member: flight_mode
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
  // member: is_armed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_connected
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
    using DataType = aether_interfaces__msg__DroneState;
    is_plain =
      (
      offsetof(DataType, is_connected) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DroneState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_aether_interfaces__msg__DroneState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneState = {
  "aether_interfaces::msg",
  "DroneState",
  _DroneState__cdr_serialize,
  _DroneState__cdr_deserialize,
  _DroneState__get_serialized_size,
  _DroneState__max_serialized_size
};

static rosidl_message_type_support_t _DroneState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, aether_interfaces, msg, DroneState)() {
  return &_DroneState__type_support;
}

#if defined(__cplusplus)
}
#endif
