// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:msg/DeconflictionWarning.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aether_interfaces__msg__DeconflictionWarning __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__msg__DeconflictionWarning __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeconflictionWarning_
{
  using Type = DeconflictionWarning_<ContainerAllocator>;

  explicit DeconflictionWarning_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id_1 = 0;
      this->drone_id_2 = 0;
      this->warning_text = "";
    }
  }

  explicit DeconflictionWarning_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    warning_text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id_1 = 0;
      this->drone_id_2 = 0;
      this->warning_text = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _drone_id_1_type =
    uint8_t;
  _drone_id_1_type drone_id_1;
  using _drone_id_2_type =
    uint8_t;
  _drone_id_2_type drone_id_2;
  using _warning_text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _warning_text_type warning_text;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__drone_id_1(
    const uint8_t & _arg)
  {
    this->drone_id_1 = _arg;
    return *this;
  }
  Type & set__drone_id_2(
    const uint8_t & _arg)
  {
    this->drone_id_2 = _arg;
    return *this;
  }
  Type & set__warning_text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->warning_text = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__msg__DeconflictionWarning
    std::shared_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__msg__DeconflictionWarning
    std::shared_ptr<aether_interfaces::msg::DeconflictionWarning_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeconflictionWarning_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->drone_id_1 != other.drone_id_1) {
      return false;
    }
    if (this->drone_id_2 != other.drone_id_2) {
      return false;
    }
    if (this->warning_text != other.warning_text) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeconflictionWarning_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeconflictionWarning_

// alias to use template instance with default allocator
using DeconflictionWarning =
  aether_interfaces::msg::DeconflictionWarning_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__DECONFLICTION_WARNING__STRUCT_HPP_
