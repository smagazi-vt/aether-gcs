// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:srv/UploadMission.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__BUILDER_HPP_
#define AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/srv/detail/upload_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace srv
{

namespace builder
{

class Init_UploadMission_Request_target_system_id
{
public:
  explicit Init_UploadMission_Request_target_system_id(::aether_interfaces::srv::UploadMission_Request & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::srv::UploadMission_Request target_system_id(::aether_interfaces::srv::UploadMission_Request::_target_system_id_type arg)
  {
    msg_.target_system_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::srv::UploadMission_Request msg_;
};

class Init_UploadMission_Request_file_path
{
public:
  Init_UploadMission_Request_file_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UploadMission_Request_target_system_id file_path(::aether_interfaces::srv::UploadMission_Request::_file_path_type arg)
  {
    msg_.file_path = std::move(arg);
    return Init_UploadMission_Request_target_system_id(msg_);
  }

private:
  ::aether_interfaces::srv::UploadMission_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::srv::UploadMission_Request>()
{
  return aether_interfaces::srv::builder::Init_UploadMission_Request_file_path();
}

}  // namespace aether_interfaces


namespace aether_interfaces
{

namespace srv
{

namespace builder
{

class Init_UploadMission_Response_message
{
public:
  explicit Init_UploadMission_Response_message(::aether_interfaces::srv::UploadMission_Response & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::srv::UploadMission_Response message(::aether_interfaces::srv::UploadMission_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::srv::UploadMission_Response msg_;
};

class Init_UploadMission_Response_success
{
public:
  Init_UploadMission_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UploadMission_Response_message success(::aether_interfaces::srv::UploadMission_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UploadMission_Response_message(msg_);
  }

private:
  ::aether_interfaces::srv::UploadMission_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::srv::UploadMission_Response>()
{
  return aether_interfaces::srv::builder::Init_UploadMission_Response_success();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__BUILDER_HPP_
