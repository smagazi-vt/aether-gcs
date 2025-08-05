// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/deconfliction_warning__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `warning_text`
#include "rosidl_runtime_c/string_functions.h"

bool
aether_interfaces__msg__DeconflictionWarning__init(aether_interfaces__msg__DeconflictionWarning * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    aether_interfaces__msg__DeconflictionWarning__fini(msg);
    return false;
  }
  // drone_id_1
  // drone_id_2
  // warning_text
  if (!rosidl_runtime_c__String__init(&msg->warning_text)) {
    aether_interfaces__msg__DeconflictionWarning__fini(msg);
    return false;
  }
  return true;
}

void
aether_interfaces__msg__DeconflictionWarning__fini(aether_interfaces__msg__DeconflictionWarning * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // drone_id_1
  // drone_id_2
  // warning_text
  rosidl_runtime_c__String__fini(&msg->warning_text);
}

bool
aether_interfaces__msg__DeconflictionWarning__are_equal(const aether_interfaces__msg__DeconflictionWarning * lhs, const aether_interfaces__msg__DeconflictionWarning * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // drone_id_1
  if (lhs->drone_id_1 != rhs->drone_id_1) {
    return false;
  }
  // drone_id_2
  if (lhs->drone_id_2 != rhs->drone_id_2) {
    return false;
  }
  // warning_text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->warning_text), &(rhs->warning_text)))
  {
    return false;
  }
  return true;
}

bool
aether_interfaces__msg__DeconflictionWarning__copy(
  const aether_interfaces__msg__DeconflictionWarning * input,
  aether_interfaces__msg__DeconflictionWarning * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // drone_id_1
  output->drone_id_1 = input->drone_id_1;
  // drone_id_2
  output->drone_id_2 = input->drone_id_2;
  // warning_text
  if (!rosidl_runtime_c__String__copy(
      &(input->warning_text), &(output->warning_text)))
  {
    return false;
  }
  return true;
}

aether_interfaces__msg__DeconflictionWarning *
aether_interfaces__msg__DeconflictionWarning__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DeconflictionWarning * msg = (aether_interfaces__msg__DeconflictionWarning *)allocator.allocate(sizeof(aether_interfaces__msg__DeconflictionWarning), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__msg__DeconflictionWarning));
  bool success = aether_interfaces__msg__DeconflictionWarning__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__msg__DeconflictionWarning__destroy(aether_interfaces__msg__DeconflictionWarning * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__msg__DeconflictionWarning__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__msg__DeconflictionWarning__Sequence__init(aether_interfaces__msg__DeconflictionWarning__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DeconflictionWarning * data = NULL;

  if (size) {
    data = (aether_interfaces__msg__DeconflictionWarning *)allocator.zero_allocate(size, sizeof(aether_interfaces__msg__DeconflictionWarning), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__msg__DeconflictionWarning__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__msg__DeconflictionWarning__fini(&data[i - 1]);
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
aether_interfaces__msg__DeconflictionWarning__Sequence__fini(aether_interfaces__msg__DeconflictionWarning__Sequence * array)
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
      aether_interfaces__msg__DeconflictionWarning__fini(&array->data[i]);
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

aether_interfaces__msg__DeconflictionWarning__Sequence *
aether_interfaces__msg__DeconflictionWarning__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__DeconflictionWarning__Sequence * array = (aether_interfaces__msg__DeconflictionWarning__Sequence *)allocator.allocate(sizeof(aether_interfaces__msg__DeconflictionWarning__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__msg__DeconflictionWarning__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__msg__DeconflictionWarning__Sequence__destroy(aether_interfaces__msg__DeconflictionWarning__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__msg__DeconflictionWarning__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__msg__DeconflictionWarning__Sequence__are_equal(const aether_interfaces__msg__DeconflictionWarning__Sequence * lhs, const aether_interfaces__msg__DeconflictionWarning__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__msg__DeconflictionWarning__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__msg__DeconflictionWarning__Sequence__copy(
  const aether_interfaces__msg__DeconflictionWarning__Sequence * input,
  aether_interfaces__msg__DeconflictionWarning__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__msg__DeconflictionWarning);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__msg__DeconflictionWarning * data =
      (aether_interfaces__msg__DeconflictionWarning *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__msg__DeconflictionWarning__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__msg__DeconflictionWarning__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__msg__DeconflictionWarning__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
