// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__BUILDER_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aether_interfaces/msg/detail/deconfliction_warning__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aether_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeconflictionWarning_warning_text
{
public:
  explicit Init_DeconflictionWarning_warning_text(::aether_interfaces::msg::DeconflictionWarning & msg)
  : msg_(msg)
  {}
  ::aether_interfaces::msg::DeconflictionWarning warning_text(::aether_interfaces::msg::DeconflictionWarning::_warning_text_type arg)
  {
    msg_.warning_text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aether_interfaces::msg::DeconflictionWarning msg_;
};

class Init_DeconflictionWarning_drone_id_2
{
public:
  explicit Init_DeconflictionWarning_drone_id_2(::aether_interfaces::msg::DeconflictionWarning & msg)
  : msg_(msg)
  {}
  Init_DeconflictionWarning_warning_text drone_id_2(::aether_interfaces::msg::DeconflictionWarning::_drone_id_2_type arg)
  {
    msg_.drone_id_2 = std::move(arg);
    return Init_DeconflictionWarning_warning_text(msg_);
  }

private:
  ::aether_interfaces::msg::DeconflictionWarning msg_;
};

class Init_DeconflictionWarning_drone_id_1
{
public:
  explicit Init_DeconflictionWarning_drone_id_1(::aether_interfaces::msg::DeconflictionWarning & msg)
  : msg_(msg)
  {}
  Init_DeconflictionWarning_drone_id_2 drone_id_1(::aether_interfaces::msg::DeconflictionWarning::_drone_id_1_type arg)
  {
    msg_.drone_id_1 = std::move(arg);
    return Init_DeconflictionWarning_drone_id_2(msg_);
  }

private:
  ::aether_interfaces::msg::DeconflictionWarning msg_;
};

class Init_DeconflictionWarning_header
{
public:
  Init_DeconflictionWarning_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeconflictionWarning_drone_id_1 header(::aether_interfaces::msg::DeconflictionWarning::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DeconflictionWarning_drone_id_1(msg_);
  }

private:
  ::aether_interfaces::msg::DeconflictionWarning msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aether_interfaces::msg::DeconflictionWarning>()
{
  return aether_interfaces::msg::builder::Init_DeconflictionWarning_header();
}

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__BUILDER_HPP_
