// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__BUILDER_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/msg/detail/calibration_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace msg
{

namespace builder
{

class Init_CalibrationStatus_success
{
public:
  explicit Init_CalibrationStatus_success(::aether_interfaces::msg::CalibrationStatus & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::msg::CalibrationStatus success(::aether_interfaces::msg::CalibrationStatus::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::msg::CalibrationStatus msg_;
};

class Init_CalibrationStatus_is_complete
{
public:
  explicit Init_CalibrationStatus_is_complete(::aether_interfaces::msg::CalibrationStatus & msg)
  : msg_(msg)
  {}
  Init_CalibrationStatus_success is_complete(::aether_interfaces::msg::CalibrationStatus::_is_complete_type arg)
  {
    msg_.is_complete = std::move(arg);
    return Init_CalibrationStatus_success(msg_);
  }

private:
  ::aether_interfaces::msg::CalibrationStatus msg_;
};

class Init_CalibrationStatus_progress_percentage
{
public:
  explicit Init_CalibrationStatus_progress_percentage(::aether_interfaces::msg::CalibrationStatus & msg)
  : msg_(msg)
  {}
  Init_CalibrationStatus_is_complete progress_percentage(::aether_interfaces::msg::CalibrationStatus::_progress_percentage_type arg)
  {
    msg_.progress_percentage = std::move(arg);
    return Init_CalibrationStatus_is_complete(msg_);
  }

private:
  ::aether_interfaces::msg::CalibrationStatus msg_;
};

class Init_CalibrationStatus_instruction_text
{
public:
  explicit Init_CalibrationStatus_instruction_text(::aether_interfaces::msg::CalibrationStatus & msg)
  : msg_(msg)
  {}
  Init_CalibrationStatus_progress_percentage instruction_text(::aether_interfaces::msg::CalibrationStatus::_instruction_text_type arg)
  {
    msg_.instruction_text = std::move(arg);
    return Init_CalibrationStatus_progress_percentage(msg_);
  }

private:
  ::aether_interfaces::msg::CalibrationStatus msg_;
};

class Init_CalibrationStatus_system_id
{
public:
  Init_CalibrationStatus_system_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrationStatus_instruction_text system_id(::aether_interfaces::msg::CalibrationStatus::_system_id_type arg)
  {
    msg_.system_id = std::move(arg);
    return Init_CalibrationStatus_instruction_text(msg_);
  }

private:
  ::aether_interfaces::msg::CalibrationStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::msg::CalibrationStatus>()
{
  return aether_interfaces::msg::builder::Init_CalibrationStatus_system_id();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__BUILDER_HPP_
