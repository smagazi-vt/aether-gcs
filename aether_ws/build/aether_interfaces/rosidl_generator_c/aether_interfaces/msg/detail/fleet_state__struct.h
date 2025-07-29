// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_H_
#define AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'drones'
#include "aether_interfaces/msg/detail/drone_state__struct.h"

/// Struct defined in msg/FleetState in the package aether_interfaces.
/**
  * Represents the state of the entire fleet.
  * It contains a list of DroneState messages.
 */
typedef struct aether_interfaces__msg__FleetState
{
  std_msgs__msg__Header header;
  aether_interfaces__msg__DroneState__Sequence drones;
} aether_interfaces__msg__FleetState;

// Struct for a sequence of aether_interfaces__msg__FleetState.
typedef struct aether_interfaces__msg__FleetState__Sequence
{
  aether_interfaces__msg__FleetState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__msg__FleetState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_H_
