// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__msg__DroneState __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__msg__DroneState __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DroneState_
{
  using Type = DroneState_<ContainerAllocator>;

  explicit DroneState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_id = 0;
      this->firmware_type = "";
      this->flight_mode = "";
      this->is_armed = false;
      this->is_connected = false;
    }
  }

  explicit DroneState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : firmware_type(_alloc),
    flight_mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_id = 0;
      this->firmware_type = "";
      this->flight_mode = "";
      this->is_armed = false;
      this->is_connected = false;
    }
  }

  // field types and members
  using _system_id_type =
    uint8_t;
  _system_id_type system_id;
  using _firmware_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _firmware_type_type firmware_type;
  using _flight_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _flight_mode_type flight_mode;
  using _is_armed_type =
    bool;
  _is_armed_type is_armed;
  using _is_connected_type =
    bool;
  _is_connected_type is_connected;

  // setters for named parameter idiom
  Type & set__system_id(
    const uint8_t & _arg)
  {
    this->system_id = _arg;
    return *this;
  }
  Type & set__firmware_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->firmware_type = _arg;
    return *this;
  }
  Type & set__flight_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->flight_mode = _arg;
    return *this;
  }
  Type & set__is_armed(
    const bool & _arg)
  {
    this->is_armed = _arg;
    return *this;
  }
  Type & set__is_connected(
    const bool & _arg)
  {
    this->is_connected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::msg::DroneState_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::msg::DroneState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::DroneState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::DroneState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__msg__DroneState
    std::shared_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__msg__DroneState
    std::shared_ptr<aether_interfaces::msg::DroneState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneState_ & other) const
  {
    if (this->system_id != other.system_id) {
      return false;
    }
    if (this->firmware_type != other.firmware_type) {
      return false;
    }
    if (this->flight_mode != other.flight_mode) {
      return false;
    }
    if (this->is_armed != other.is_armed) {
      return false;
    }
    if (this->is_connected != other.is_connected) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneState_

// alias to use template instance with default allocator
using DroneState =
  aether_interfaces::msg::DroneState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__DRONE_STATE__STRUCT_HPP_
