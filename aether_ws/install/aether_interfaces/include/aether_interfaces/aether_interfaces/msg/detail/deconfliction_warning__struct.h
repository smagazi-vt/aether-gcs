// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_H_
#define AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_H_

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
// Member 'warning_text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DeconflictionWarning in the package aether_interfaces.
/**
  * A strategic warning from the GCS
 */
typedef struct aether_interfaces__msg__DeconflictionWarning
{
  std_msgs__msg__Header header;
  uint8_t drone_id_1;
  uint8_t drone_id_2;
  /// e.g., "Mission for Drone 1 conflicts with Drone 2's area"
  rosidl_runtime_c__String warning_text;
} aether_interfaces__msg__DeconflictionWarning;

// Struct for a sequence of aether_interfaces__msg__DeconflictionWarning.
typedef struct aether_interfaces__msg__DeconflictionWarning__Sequence
{
  aether_interfaces__msg__DeconflictionWarning * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__msg__DeconflictionWarning__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_H_
