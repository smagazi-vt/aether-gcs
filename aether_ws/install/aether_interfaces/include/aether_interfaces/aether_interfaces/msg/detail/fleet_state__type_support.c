// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aether_interfaces/msg/detail/fleet_state__rosidl_typesupport_introspection_c.h"
#include "aether_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aether_interfaces/msg/detail/fleet_state__functions.h"
#include "aether_interfaces/msg/detail/fleet_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `drones`
#include "aether_interfaces/msg/drone_state.h"
// Member `drones`
#include "aether_interfaces/msg/detail/drone_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aether_interfaces__msg__FleetState__init(message_memory);
}

void aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_fini_function(void * message_memory)
{
  aether_interfaces__msg__FleetState__fini(message_memory);
}

size_t aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__size_function__FleetState__drones(
  const void * untyped_member)
{
  const aether_interfaces__msg__DroneState__Sequence * member =
    (const aether_interfaces__msg__DroneState__Sequence *)(untyped_member);
  return member->size;
}

const void * aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_const_function__FleetState__drones(
  const void * untyped_member, size_t index)
{
  const aether_interfaces__msg__DroneState__Sequence * member =
    (const aether_interfaces__msg__DroneState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_function__FleetState__drones(
  void * untyped_member, size_t index)
{
  aether_interfaces__msg__DroneState__Sequence * member =
    (aether_interfaces__msg__DroneState__Sequence *)(untyped_member);
  return &member->data[index];
}

void aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__fetch_function__FleetState__drones(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const aether_interfaces__msg__DroneState * item =
    ((const aether_interfaces__msg__DroneState *)
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_const_function__FleetState__drones(untyped_member, index));
  aether_interfaces__msg__DroneState * value =
    (aether_interfaces__msg__DroneState *)(untyped_value);
  *value = *item;
}

void aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__assign_function__FleetState__drones(
  void * untyped_member, size_t index, const void * untyped_value)
{
  aether_interfaces__msg__DroneState * item =
    ((aether_interfaces__msg__DroneState *)
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_function__FleetState__drones(untyped_member, index));
  const aether_interfaces__msg__DroneState * value =
    (const aether_interfaces__msg__DroneState *)(untyped_value);
  *item = *value;
}

bool aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__resize_function__FleetState__drones(
  void * untyped_member, size_t size)
{
  aether_interfaces__msg__DroneState__Sequence * member =
    (aether_interfaces__msg__DroneState__Sequence *)(untyped_member);
  aether_interfaces__msg__DroneState__Sequence__fini(member);
  return aether_interfaces__msg__DroneState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__FleetState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__msg__FleetState, drones),  // bytes offset in struct
    NULL,  // default value
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__size_function__FleetState__drones,  // size() function pointer
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_const_function__FleetState__drones,  // get_const(index) function pointer
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__get_function__FleetState__drones,  // get(index) function pointer
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__fetch_function__FleetState__drones,  // fetch(index, &value) function pointer
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__assign_function__FleetState__drones,  // assign(index, value) function pointer
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__resize_function__FleetState__drones  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_members = {
  "aether_interfaces__msg",  // message namespace
  "FleetState",  // message name
  2,  // number of fields
  sizeof(aether_interfaces__msg__FleetState),
  aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_member_array,  // message members
  aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_init_function,  // function to initialize message memory (memory has to be allocated)
  aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_type_support_handle = {
  0,
  &aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aether_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, msg, FleetState)() {
  aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, msg, DroneState)();
  if (!aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_type_support_handle.typesupport_identifier) {
    aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aether_interfaces__msg__FleetState__rosidl_typesupport_introspection_c__FleetState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
