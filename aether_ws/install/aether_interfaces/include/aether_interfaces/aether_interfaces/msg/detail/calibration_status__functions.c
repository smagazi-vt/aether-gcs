// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/calibration_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `instruction_text`
#include "rosidl_runtime_c/string_functions.h"

bool
aether_interfaces__msg__CalibrationStatus__init(aether_interfaces__msg__CalibrationStatus * msg)
{
  if (!msg) {
    return false;
  }
  // system_id
  // instruction_text
  if (!rosidl_runtime_c__String__init(&msg->instruction_text)) {
    aether_interfaces__msg__CalibrationStatus__fini(msg);
    return false;
  }
  // progress_percentage
  // is_complete
  // success
  return true;
}

void
aether_interfaces__msg__CalibrationStatus__fini(aether_interfaces__msg__CalibrationStatus * msg)
{
  if (!msg) {
    return;
  }
  // system_id
  // instruction_text
  rosidl_runtime_c__String__fini(&msg->instruction_text);
  // progress_percentage
  // is_complete
  // success
}

bool
aether_interfaces__msg__CalibrationStatus__are_equal(const aether_interfaces__msg__CalibrationStatus * lhs, const aether_interfaces__msg__CalibrationStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // system_id
  if (lhs->system_id != rhs->system_id) {
    return false;
  }
  // instruction_text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->instruction_text), &(rhs->instruction_text)))
  {
    return false;
  }
  // progress_percentage
  if (lhs->progress_percentage != rhs->progress_percentage) {
    return false;
  }
  // is_complete
  if (lhs->is_complete != rhs->is_complete) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
aether_interfaces__msg__CalibrationStatus__copy(
  const aether_interfaces__msg__CalibrationStatus * input,
  aether_interfaces__msg__CalibrationStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // system_id
  output->system_id = input->system_id;
  // instruction_text
  if (!rosidl_runtime_c__String__copy(
      &(input->instruction_text), &(output->instruction_text)))
  {
    return false;
  }
  // progress_percentage
  output->progress_percentage = input->progress_percentage;
  // is_complete
  output->is_complete = input->is_complete;
  // success
  output->success = input->success;
  return true;
}

aether_interfaces__msg__CalibrationStatus *
aether_interfaces__msg__CalibrationStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__CalibrationStatus * msg = (aether_interfaces__msg__CalibrationStatus *)allocator.allocate(sizeof(aether_interfaces__msg__CalibrationStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__msg__CalibrationStatus));
  bool success = aether_interfaces__msg__CalibrationStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__msg__CalibrationStatus__destroy(aether_interfaces__msg__CalibrationStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__msg__CalibrationStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__msg__CalibrationStatus__Sequence__init(aether_interfaces__msg__CalibrationStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__CalibrationStatus * data = NULL;

  if (size) {
    data = (aether_interfaces__msg__CalibrationStatus *)allocator.zero_allocate(size, sizeof(aether_interfaces__msg__CalibrationStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__msg__CalibrationStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__msg__CalibrationStatus__fini(&data[i - 1]);
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
aether_interfaces__msg__CalibrationStatus__Sequence__fini(aether_interfaces__msg__CalibrationStatus__Sequence * array)
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
      aether_interfaces__msg__CalibrationStatus__fini(&array->data[i]);
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

aether_interfaces__msg__CalibrationStatus__Sequence *
aether_interfaces__msg__CalibrationStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__CalibrationStatus__Sequence * array = (aether_interfaces__msg__CalibrationStatus__Sequence *)allocator.allocate(sizeof(aether_interfaces__msg__CalibrationStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__msg__CalibrationStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__msg__CalibrationStatus__Sequence__destroy(aether_interfaces__msg__CalibrationStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__msg__CalibrationStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__msg__CalibrationStatus__Sequence__are_equal(const aether_interfaces__msg__CalibrationStatus__Sequence * lhs, const aether_interfaces__msg__CalibrationStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__msg__CalibrationStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__msg__CalibrationStatus__Sequence__copy(
  const aether_interfaces__msg__CalibrationStatus__Sequence * input,
  aether_interfaces__msg__CalibrationStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__msg__CalibrationStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__msg__CalibrationStatus * data =
      (aether_interfaces__msg__CalibrationStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__msg__CalibrationStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__msg__CalibrationStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__msg__CalibrationStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
