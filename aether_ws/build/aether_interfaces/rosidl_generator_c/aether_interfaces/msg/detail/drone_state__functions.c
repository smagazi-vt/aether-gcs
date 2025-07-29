// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/drone_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `firmware_type`
// Member `flight_mode`
#include "rosidl_runtime_c/string_functions.h"

bool
aether_interfaces__msg__DroneState__init(aether_interfaces__msg__DroneState * msg)
{
  if (!msg) {
    return false;
  }
  // system_id
  // firmware_type
  if (!rosidl_runtime_c__String__init(&msg->firmware_type)) {
    aether_interfaces__msg__DroneState__fini(msg);
    return false;
  }
  // flight_mode
  if (!rosidl_runtime_c__String__init(&msg->flight_mode)) {
    aether_interfaces__msg__DroneState__fini(msg);
    return false;
  }
  // is_armed
  // is_connected
  return true;
}

void
aether_interfaces__msg__DroneState__fini(aether_interfaces__msg__DroneState * msg)
{
  if (!msg) {
    return;
  }
  // system_id
  // firmware_type
  rosidl_runtime_c__String__fini(&msg->firmware_type);
  // flight_mode
  rosidl_runtime_c__String__fini(&msg->flight_mode);
  // is_armed
  // is_connected
}

bool
aether_interfaces__msg__DroneState__are_equal(const aether_interfaces__msg__DroneState * lhs, const aether_interfaces__msg__DroneState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // system_id
  if (lhs->system_id != rhs->system_id) {
    return false;
  }
  // firmware_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->firmware_type), &(rhs->firmware_type)))
  {
    return false;
  }
  // flight_mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->flight_mode), &(rhs->flight_mode)))
  {
    return false;
  }
  // is_armed
  if (lhs->is_armed != rhs->is_armed) {
    return false;
  }
  // is_connected
  if (lhs->is_connected != rhs->is_connected) {
    return false;
  }
  return true;
}

bool
aether_interfaces__msg__DroneState__copy(
  const aether_interfaces__msg__DroneState * input,
  aether_interfaces__msg__DroneState * output)
{
  if (!input || !output) {
    return false;
  }
  // system_id
  output->system_id = input->system_id;
  // firmware_type
  if (!rosidl_runtime_c__String__copy(
      &(input->firmware_type), &(output->firmware_type)))
  {
    return false;
  }
  // flight_mode
  if (!rosidl_runtime_c__String__copy(
      &(input->flight_mode), &(output->flight_mode)))
  {
    return false;
  }
  // is_armed
  output->is_armed = input->is_armed;
  // is_connected
  output->is_connected = input->is_connected;
  return true;
}

aether_interfaces__msg__DroneState *
aether_interfaces__msg__DroneState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DroneState * msg = (aether_interfaces__msg__DroneState *)allocator.allocate(sizeof(aether_interfaces__msg__DroneState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__msg__DroneState));
  bool success = aether_interfaces__msg__DroneState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__msg__DroneState__destroy(aether_interfaces__msg__DroneState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__msg__DroneState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__msg__DroneState__Sequence__init(aether_interfaces__msg__DroneState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DroneState * data = NULL;

  if (size) {
    data = (aether_interfaces__msg__DroneState *)allocator.zero_allocate(size, sizeof(aether_interfaces__msg__DroneState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__msg__DroneState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__msg__DroneState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
aether_interfaces__msg__DroneState__Sequence__fini(aether_interfaces__msg__DroneState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      aether_interfaces__msg__DroneState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

aether_interfaces__msg__DroneState__Sequence *
aether_interfaces__msg__DroneState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DroneState__Sequence * array = (aether_interfaces__msg__DroneState__Sequence *)allocator.allocate(sizeof(aether_interfaces__msg__DroneState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__msg__DroneState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__msg__DroneState__Sequence__destroy(aether_interfaces__msg__DroneState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__msg__DroneState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__msg__DroneState__Sequence__are_equal(const aether_interfaces__msg__DroneState__Sequence * lhs, const aether_interfaces__msg__DroneState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__msg__DroneState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__msg__DroneState__Sequence__copy(
  const aether_interfaces__msg__DroneState__Sequence * input,
  aether_interfaces__msg__DroneState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__msg__DroneState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__msg__DroneState * data =
      (aether_interfaces__msg__DroneState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__msg__DroneState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__msg__DroneState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__msg__DroneState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
