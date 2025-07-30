// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from aether_interfaces:srv/UploadMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "aether_interfaces/srv/detail/upload_mission__rosidl_typesupport_introspection_c.h"
#include "aether_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "aether_interfaces/srv/detail/upload_mission__functions.h"
#include "aether_interfaces/srv/detail/upload_mission__struct.h"


// Include directives for member types
// Member `file_path`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aether_interfaces__srv__UploadMission_Request__init(message_memory);
}

void aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_fini_function(void * message_memory)
{
  aether_interfaces__srv__UploadMission_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_member_array[2] = {
  {
    "file_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__srv__UploadMission_Request, file_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_system_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__srv__UploadMission_Request, target_system_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_members = {
  "aether_interfaces__srv",  // message namespace
  "UploadMission_Request",  // message name
  2,  // number of fields
  sizeof(aether_interfaces__srv__UploadMission_Request),
  aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_member_array,  // message members
  aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_type_support_handle = {
  0,
  &aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aether_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Request)() {
  if (!aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_type_support_handle.typesupport_identifier) {
    aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aether_interfaces__srv__UploadMission_Request__rosidl_typesupport_introspection_c__UploadMission_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "aether_interfaces/srv/detail/upload_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "aether_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "aether_interfaces/srv/detail/upload_mission__functions.h"
// already included above
// #include "aether_interfaces/srv/detail/upload_mission__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  aether_interfaces__srv__UploadMission_Response__init(message_memory);
}

void aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_fini_function(void * message_memory)
{
  aether_interfaces__srv__UploadMission_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__srv__UploadMission_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(aether_interfaces__srv__UploadMission_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_members = {
  "aether_interfaces__srv",  // message namespace
  "UploadMission_Response",  // message name
  2,  // number of fields
  sizeof(aether_interfaces__srv__UploadMission_Response),
  aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_member_array,  // message members
  aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_type_support_handle = {
  0,
  &aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aether_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Response)() {
  if (!aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_type_support_handle.typesupport_identifier) {
    aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &aether_interfaces__srv__UploadMission_Response__rosidl_typesupport_introspection_c__UploadMission_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "aether_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "aether_interfaces/srv/detail/upload_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_members = {
  "aether_interfaces__srv",  // service namespace
  "UploadMission",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_Request_message_type_support_handle,
  NULL  // response message
  // aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_Response_message_type_support_handle
};

static rosidl_service_type_support_t aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_type_support_handle = {
  0,
  &aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_aether_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission)() {
  if (!aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_type_support_handle.typesupport_identifier) {
    aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, aether_interfaces, srv, UploadMission_Response)()->data;
  }

  return &aether_interfaces__srv__detail__upload_mission__rosidl_typesupport_introspection_c__UploadMission_service_type_support_handle;
}
