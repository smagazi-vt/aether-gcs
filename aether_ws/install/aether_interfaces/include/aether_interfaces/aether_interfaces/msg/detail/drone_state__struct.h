// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_H_
#define AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'firmware_type'
// Member 'flight_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DroneState in the package aether_interfaces.
/**
  * Represents the standardized state of a single drone in the fleet.
 */
typedef struct aether_interfaces__msg__DroneState
{
  uint8_t system_id;
  rosidl_runtime_c__String firmware_type;
  rosidl_runtime_c__String flight_mode;
  bool is_armed;
  bool is_connected;
} aether_interfaces__msg__DroneState;

// Struct for a sequence of aether_interfaces__msg__DroneState.
typedef struct aether_interfaces__msg__DroneState__Sequence
{
  aether_interfaces__msg__DroneState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__msg__DroneState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_H_
