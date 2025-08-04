// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from aether_interfaces:srv/StartCalibration.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__FUNCTIONS_H_
#define AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "aether_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "aether_interfaces/srv/detail/start_calibration__struct.h"

/// Initialize srv/StartCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * aether_interfaces__srv__StartCalibration_Request
 * )) before or use
 * aether_interfaces__srv__StartCalibration_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__init(aether_interfaces__srv__StartCalibration_Request * msg);

/// Finalize srv/StartCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Request__fini(aether_interfaces__srv__StartCalibration_Request * msg);

/// Create srv/StartCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * aether_interfaces__srv__StartCalibration_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
aether_interfaces__srv__StartCalibration_Request *
aether_interfaces__srv__StartCalibration_Request__create();

/// Destroy srv/StartCalibration message.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Request__destroy(aether_interfaces__srv__StartCalibration_Request * msg);

/// Check for srv/StartCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__are_equal(const aether_interfaces__srv__StartCalibration_Request * lhs, const aether_interfaces__srv__StartCalibration_Request * rhs);

/// Copy a srv/StartCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__copy(
  const aether_interfaces__srv__StartCalibration_Request * input,
  aether_interfaces__srv__StartCalibration_Request * output);

/// Initialize array of srv/StartCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * aether_interfaces__srv__StartCalibration_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__Sequence__init(aether_interfaces__srv__StartCalibration_Request__Sequence * array, size_t size);

/// Finalize array of srv/StartCalibration messages.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Request__Sequence__fini(aether_interfaces__srv__StartCalibration_Request__Sequence * array);

/// Create array of srv/StartCalibration messages.
/**
 * It allocates the memory for the array and calls
 * aether_interfaces__srv__StartCalibration_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
aether_interfaces__srv__StartCalibration_Request__Sequence *
aether_interfaces__srv__StartCalibration_Request__Sequence__create(size_t size);

/// Destroy array of srv/StartCalibration messages.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Request__Sequence__destroy(aether_interfaces__srv__StartCalibration_Request__Sequence * array);

/// Check for srv/StartCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__Sequence__are_equal(const aether_interfaces__srv__StartCalibration_Request__Sequence * lhs, const aether_interfaces__srv__StartCalibration_Request__Sequence * rhs);

/// Copy an array of srv/StartCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Request__Sequence__copy(
  const aether_interfaces__srv__StartCalibration_Request__Sequence * input,
  aether_interfaces__srv__StartCalibration_Request__Sequence * output);

/// Initialize srv/StartCalibration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * aether_interfaces__srv__StartCalibration_Response
 * )) before or use
 * aether_interfaces__srv__StartCalibration_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__init(aether_interfaces__srv__StartCalibration_Response * msg);

/// Finalize srv/StartCalibration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Response__fini(aether_interfaces__srv__StartCalibration_Response * msg);

/// Create srv/StartCalibration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * aether_interfaces__srv__StartCalibration_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
aether_interfaces__srv__StartCalibration_Response *
aether_interfaces__srv__StartCalibration_Response__create();

/// Destroy srv/StartCalibration message.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Response__destroy(aether_interfaces__srv__StartCalibration_Response * msg);

/// Check for srv/StartCalibration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__are_equal(const aether_interfaces__srv__StartCalibration_Response * lhs, const aether_interfaces__srv__StartCalibration_Response * rhs);

/// Copy a srv/StartCalibration message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__copy(
  const aether_interfaces__srv__StartCalibration_Response * input,
  aether_interfaces__srv__StartCalibration_Response * output);

/// Initialize array of srv/StartCalibration messages.
/**
 * It allocates the memory for the number of elements and calls
 * aether_interfaces__srv__StartCalibration_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__Sequence__init(aether_interfaces__srv__StartCalibration_Response__Sequence * array, size_t size);

/// Finalize array of srv/StartCalibration messages.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Response__Sequence__fini(aether_interfaces__srv__StartCalibration_Response__Sequence * array);

/// Create array of srv/StartCalibration messages.
/**
 * It allocates the memory for the array and calls
 * aether_interfaces__srv__StartCalibration_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
aether_interfaces__srv__StartCalibration_Response__Sequence *
aether_interfaces__srv__StartCalibration_Response__Sequence__create(size_t size);

/// Destroy array of srv/StartCalibration messages.
/**
 * It calls
 * aether_interfaces__srv__StartCalibration_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
void
aether_interfaces__srv__StartCalibration_Response__Sequence__destroy(aether_interfaces__srv__StartCalibration_Response__Sequence * array);

/// Check for srv/StartCalibration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__Sequence__are_equal(const aether_interfaces__srv__StartCalibration_Response__Sequence * lhs, const aether_interfaces__srv__StartCalibration_Response__Sequence * rhs);

/// Copy an array of srv/StartCalibration messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_aether_interfaces
bool
aether_interfaces__srv__StartCalibration_Response__Sequence__copy(
  const aether_interfaces__srv__StartCalibration_Response__Sequence * input,
  aether_interfaces__srv__StartCalibration_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__FUNCTIONS_H_
