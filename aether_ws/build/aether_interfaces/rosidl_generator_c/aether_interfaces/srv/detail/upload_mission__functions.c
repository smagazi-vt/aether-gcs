// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from aether_interfaces:srv/UploadMission.idl
// generated code does not contain a copyright notice
#include "aether_interfaces/srv/detail/upload_mission__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `file_path`
#include "rosidl_runtime_c/string_functions.h"

bool
aether_interfaces__srv__UploadMission_Request__init(aether_interfaces__srv__UploadMission_Request * msg)
{
  if (!msg) {
    return false;
  }
  // file_path
  if (!rosidl_runtime_c__String__init(&msg->file_path)) {
    aether_interfaces__srv__UploadMission_Request__fini(msg);
    return false;
  }
  // target_system_id
  return true;
}

void
aether_interfaces__srv__UploadMission_Request__fini(aether_interfaces__srv__UploadMission_Request * msg)
{
  if (!msg) {
    return;
  }
  // file_path
  rosidl_runtime_c__String__fini(&msg->file_path);
  // target_system_id
}

bool
aether_interfaces__srv__UploadMission_Request__are_equal(const aether_interfaces__srv__UploadMission_Request * lhs, const aether_interfaces__srv__UploadMission_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // file_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->file_path), &(rhs->file_path)))
  {
    return false;
  }
  // target_system_id
  if (lhs->target_system_id != rhs->target_system_id) {
    return false;
  }
  return true;
}

bool
aether_interfaces__srv__UploadMission_Request__copy(
  const aether_interfaces__srv__UploadMission_Request * input,
  aether_interfaces__srv__UploadMission_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // file_path
  if (!rosidl_runtime_c__String__copy(
      &(input->file_path), &(output->file_path)))
  {
    return false;
  }
  // target_system_id
  output->target_system_id = input->target_system_id;
  return true;
}

aether_interfaces__srv__UploadMission_Request *
aether_interfaces__srv__UploadMission_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Request * msg = (aether_interfaces__srv__UploadMission_Request *)allocator.allocate(sizeof(aether_interfaces__srv__UploadMission_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__srv__UploadMission_Request));
  bool success = aether_interfaces__srv__UploadMission_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__srv__UploadMission_Request__destroy(aether_interfaces__srv__UploadMission_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__srv__UploadMission_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__srv__UploadMission_Request__Sequence__init(aether_interfaces__srv__UploadMission_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Request * data = NULL;

  if (size) {
    data = (aether_interfaces__srv__UploadMission_Request *)allocator.zero_allocate(size, sizeof(aether_interfaces__srv__UploadMission_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__srv__UploadMission_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__srv__UploadMission_Request__fini(&data[i - 1]);
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
aether_interfaces__srv__UploadMission_Request__Sequence__fini(aether_interfaces__srv__UploadMission_Request__Sequence * array)
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
      aether_interfaces__srv__UploadMission_Request__fini(&array->data[i]);
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

aether_interfaces__srv__UploadMission_Request__Sequence *
aether_interfaces__srv__UploadMission_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Request__Sequence * array = (aether_interfaces__srv__UploadMission_Request__Sequence *)allocator.allocate(sizeof(aether_interfaces__srv__UploadMission_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__srv__UploadMission_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__srv__UploadMission_Request__Sequence__destroy(aether_interfaces__srv__UploadMission_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__srv__UploadMission_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__srv__UploadMission_Request__Sequence__are_equal(const aether_interfaces__srv__UploadMission_Request__Sequence * lhs, const aether_interfaces__srv__UploadMission_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__srv__UploadMission_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__srv__UploadMission_Request__Sequence__copy(
  const aether_interfaces__srv__UploadMission_Request__Sequence * input,
  aether_interfaces__srv__UploadMission_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__srv__UploadMission_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__srv__UploadMission_Request * data =
      (aether_interfaces__srv__UploadMission_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__srv__UploadMission_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__srv__UploadMission_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__srv__UploadMission_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
aether_interfaces__srv__UploadMission_Response__init(aether_interfaces__srv__UploadMission_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    aether_interfaces__srv__UploadMission_Response__fini(msg);
    return false;
  }
  return true;
}

void
aether_interfaces__srv__UploadMission_Response__fini(aether_interfaces__srv__UploadMission_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
aether_interfaces__srv__UploadMission_Response__are_equal(const aether_interfaces__srv__UploadMission_Response * lhs, const aether_interfaces__srv__UploadMission_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
aether_interfaces__srv__UploadMission_Response__copy(
  const aether_interfaces__srv__UploadMission_Response * input,
  aether_interfaces__srv__UploadMission_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

aether_interfaces__srv__UploadMission_Response *
aether_interfaces__srv__UploadMission_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Response * msg = (aether_interfaces__srv__UploadMission_Response *)allocator.allocate(sizeof(aether_interfaces__srv__UploadMission_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(aether_interfaces__srv__UploadMission_Response));
  bool success = aether_interfaces__srv__UploadMission_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
aether_interfaces__srv__UploadMission_Response__destroy(aether_interfaces__srv__UploadMission_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    aether_interfaces__srv__UploadMission_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
aether_interfaces__srv__UploadMission_Response__Sequence__init(aether_interfaces__srv__UploadMission_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Response * data = NULL;

  if (size) {
    data = (aether_interfaces__srv__UploadMission_Response *)allocator.zero_allocate(size, sizeof(aether_interfaces__srv__UploadMission_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = aether_interfaces__srv__UploadMission_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        aether_interfaces__srv__UploadMission_Response__fini(&data[i - 1]);
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
aether_interfaces__srv__UploadMission_Response__Sequence__fini(aether_interfaces__srv__UploadMission_Response__Sequence * array)
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
      aether_interfaces__srv__UploadMission_Response__fini(&array->data[i]);
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

aether_interfaces__srv__UploadMission_Response__Sequence *
aether_interfaces__srv__UploadMission_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  aether_interfaces__srv__UploadMission_Response__Sequence * array = (aether_interfaces__srv__UploadMission_Response__Sequence *)allocator.allocate(sizeof(aether_interfaces__srv__UploadMission_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = aether_interfaces__srv__UploadMission_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
aether_interfaces__srv__UploadMission_Response__Sequence__destroy(aether_interfaces__srv__UploadMission_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    aether_interfaces__srv__UploadMission_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
aether_interfaces__srv__UploadMission_Response__Sequence__are_equal(const aether_interfaces__srv__UploadMission_Response__Sequence * lhs, const aether_interfaces__srv__UploadMission_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!aether_interfaces__srv__UploadMission_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
aether_interfaces__srv__UploadMission_Response__Sequence__copy(
  const aether_interfaces__srv__UploadMission_Response__Sequence * input,
  aether_interfaces__srv__UploadMission_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(aether_interfaces__srv__UploadMission_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    aether_interfaces__srv__UploadMission_Response * data =
      (aether_interfaces__srv__UploadMission_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!aether_interfaces__srv__UploadMission_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          aether_interfaces__srv__UploadMission_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!aether_interfaces__srv__UploadMission_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
