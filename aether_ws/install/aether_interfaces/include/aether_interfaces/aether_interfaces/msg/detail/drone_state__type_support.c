// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aether_interfaces/msg/detail/drone_state__rosidl_typesupport_introspection_c.h"
#include "aether_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aether_interfaces/msg/detail/drone_state__functions.h"
#include "aether_interfaces/msg/detail/drone_state__struct.h"


// Include directives for member types
// Member `firmware_type`
// Member `flight_mode`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aether_interfaces__msg__DroneState__init(message_memory);
}

void aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_fini_function(void * message_memory)
{
  aether_interfaces__msg__DroneState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_member_array[5] = {
  {
    "system_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__DroneState, system_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "firmware_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__DroneState, firmware_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flight_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__DroneState, flight_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_armed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__DroneState, is_armed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__DroneState, is_connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_members = {
  "aether_interfaces__msg",  // message namespace
  "DroneState",  // message name
  5,  // number of fields
  sizeof(aether_interfaces__msg__DroneState),
  aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_member_array,  // message members
  aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_init_function,  // function to initialize message memory (memory has to be allocated)
  aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle = {
  0,
  &aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aether_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, msg, DroneState)() {
  if (!aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle.typesupport_identifier) {
    aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aether_interfaces__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
