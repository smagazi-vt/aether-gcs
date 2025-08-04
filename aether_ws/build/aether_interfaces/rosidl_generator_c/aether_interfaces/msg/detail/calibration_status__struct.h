// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_H_
#define AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'instruction_text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CalibrationStatus in the package aether_interfaces.
/**
  * Status update for an ongoing calibration
 */
typedef struct aether_interfaces__msg__CalibrationStatus
{
  uint8_t system_id;
  rosidl_runtime_c__String instruction_text;
  /// 0.0 to 100.0
  float progress_percentage;
  bool is_complete;
  bool success;
} aether_interfaces__msg__CalibrationStatus;

// Struct for a sequence of aether_interfaces__msg__CalibrationStatus.
typedef struct aether_interfaces__msg__CalibrationStatus__Sequence
{
  aether_interfaces__msg__CalibrationStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__msg__CalibrationStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_H_
