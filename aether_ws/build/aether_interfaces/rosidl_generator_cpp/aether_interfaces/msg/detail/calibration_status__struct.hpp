// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__msg__CalibrationStatus __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__msg__CalibrationStatus __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CalibrationStatus_
{
  using Type = CalibrationStatus_<ContainerAllocator>;

  explicit CalibrationStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_id = 0;
      this->instruction_text = "";
      this->progress_percentage = 0.0f;
      this->is_complete = false;
      this->success = false;
    }
  }

  explicit CalibrationStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : instruction_text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_id = 0;
      this->instruction_text = "";
      this->progress_percentage = 0.0f;
      this->is_complete = false;
      this->success = false;
    }
  }

  // field types and members
  using _system_id_type =
    uint8_t;
  _system_id_type system_id;
  using _instruction_text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _instruction_text_type instruction_text;
  using _progress_percentage_type =
    float;
  _progress_percentage_type progress_percentage;
  using _is_complete_type =
    bool;
  _is_complete_type is_complete;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__system_id(
    const uint8_t & _arg)
  {
    this->system_id = _arg;
    return *this;
  }
  Type & set__instruction_text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->instruction_text = _arg;
    return *this;
  }
  Type & set__progress_percentage(
    const float & _arg)
  {
    this->progress_percentage = _arg;
    return *this;
  }
  Type & set__is_complete(
    const bool & _arg)
  {
    this->is_complete = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__msg__CalibrationStatus
    std::shared_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__msg__CalibrationStatus
    std::shared_ptr<aether_interfaces::msg::CalibrationStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrationStatus_ & other) const
  {
    if (this->system_id != other.system_id) {
      return false;
    }
    if (this->instruction_text != other.instruction_text) {
      return false;
    }
    if (this->progress_percentage != other.progress_percentage) {
      return false;
    }
    if (this->is_complete != other.is_complete) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrationStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrationStatus_

// alias to use template instance with default allocator
using CalibrationStatus =
  aether_interfaces::msg::CalibrationStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__CALIBRATION_STATUS__STRUCT_HPP_
