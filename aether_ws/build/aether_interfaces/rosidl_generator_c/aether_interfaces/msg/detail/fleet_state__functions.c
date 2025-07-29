// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/msg/detail/fleet_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `drones`
#include "aether_interfaces/msg/detail/drone_state__functions.h"

bool
aether_interfaces__msg__FleetState__init(aether_interfaces__msg__FleetState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    aether_interfaces__msg__FleetState__fini(msg);
    return false;
  }
  // drones
  if (!aether_interfaces__msg__DroneState__Sequence__init(&msg->drones, 0)) {
    aether_interfaces__msg__FleetState__fini(msg);
    return false;
  }
  return true;
}

void
aether_interfaces__msg__FleetState__fini(aether_interfaces__msg__FleetState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // drones
  aether_interfaces__msg__DroneState__Sequence__fini(&msg->drones);
}

bool
aether_interfaces__msg__FleetState__are_equal(const aether_interfaces__msg__FleetState * lhs, const aether_interfaces__msg__FleetState * rhs)
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
  // drones
  if (!aether_interfaces__msg__DroneState__Sequence__are_equal(
      &(lhs->drones), &(rhs->drones)))
  {
    return false;
  }
  return true;
}

bool
aether_interfaces__msg__FleetState__copy(
  const aether_interfaces__msg__FleetState * input,
  aether_interfaces__msg__FleetState * output)
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
  // drones
  if (!aether_interfaces__msg__DroneState__Sequence__copy(
      &(input->drones), &(output->drones)))
  {
    return false;
  }
  return true;
}

aether_interfaces__msg__FleetState *
aether_interfaces__msg__FleetState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__FleetState * msg = (aether_interfaces__msg__FleetState *)allocator.allocate(sizeof(aether_interfaces__msg__FleetState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__msg__FleetState));
  bool success = aether_interfaces__msg__FleetState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__msg__FleetState__destroy(aether_interfaces__msg__FleetState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__msg__FleetState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__msg__FleetState__Sequence__init(aether_interfaces__msg__FleetState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__FleetState * data = NULL;

  if (size) {
    data = (aether_interfaces__msg__FleetState *)allocator.zero_allocate(size, sizeof(aether_interfaces__msg__FleetState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__msg__FleetState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__msg__FleetState__fini(&data[i - 1]);
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
aether_interfaces__msg__FleetState__Sequence__fini(aether_interfaces__msg__FleetState__Sequence * array)
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
      aether_interfaces__msg__FleetState__fini(&array->data[i]);
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

aether_interfaces__msg__FleetState__Sequence *
aether_interfaces__msg__FleetState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__msg__FleetState__Sequence * array = (aether_interfaces__msg__FleetState__Sequence *)allocator.allocate(sizeof(aether_interfaces__msg__FleetState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__msg__FleetState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__msg__FleetState__Sequence__destroy(aether_interfaces__msg__FleetState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__msg__FleetState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__msg__FleetState__Sequence__are_equal(const aether_interfaces__msg__FleetState__Sequence * lhs, const aether_interfaces__msg__FleetState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__msg__FleetState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__msg__FleetState__Sequence__copy(
  const aether_interfaces__msg__FleetState__Sequence * input,
  aether_interfaces__msg__FleetState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__msg__FleetState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__msg__FleetState * data =
      (aether_interfaces__msg__FleetState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__msg__FleetState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__msg__FleetState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__msg__FleetState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
