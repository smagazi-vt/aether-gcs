// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aether_interfaces:srv/StartCalibration.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_H_
#define AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensor_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartCalibration in the package aether_interfaces.
typedef struct aether_interfaces__srv__StartCalibration_Request
{
  uint8_t target_system_id;
  /// e.g., "accel", "gyro", "mag"
  rosidl_runtime_c__String sensor_type;
} aether_interfaces__srv__StartCalibration_Request;

// Struct for a sequence of aether_interfaces__srv__StartCalibration_Request.
typedef struct aether_interfaces__srv__StartCalibration_Request__Sequence
{
  aether_interfaces__srv__StartCalibration_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__srv__StartCalibration_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartCalibration in the package aether_interfaces.
typedef struct aether_interfaces__srv__StartCalibration_Response
{
  bool success;
  rosidl_runtime_c__String message;
} aether_interfaces__srv__StartCalibration_Response;

// Struct for a sequence of aether_interfaces__srv__StartCalibration_Response.
typedef struct aether_interfaces__srv__StartCalibration_Response__Sequence
{
  aether_interfaces__srv__StartCalibration_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aether_interfaces__srv__StartCalibration_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_H_
