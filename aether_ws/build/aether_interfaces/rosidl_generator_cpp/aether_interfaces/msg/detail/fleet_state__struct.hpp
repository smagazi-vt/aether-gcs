// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:msg/FleetState.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_HPP_
#define AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_HPP_

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
// Member 'drones'
#include "aether_interfaces/msg/detail/drone_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__aether_interfaces__msg__FleetState __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__msg__FleetState __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FleetState_
{
  using Type = FleetState_<ContainerAllocator>;

  explicit FleetState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit FleetState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _drones_type =
    std::vector<aether_interfaces::msg::DroneState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<aether_interfaces::msg::DroneState_<ContainerAllocator>>>;
  _drones_type drones;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__drones(
    const std::vector<aether_interfaces::msg::DroneState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<aether_interfaces::msg::DroneState_<ContainerAllocator>>> & _arg)
  {
    this->drones = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::msg::FleetState_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::msg::FleetState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::FleetState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::msg::FleetState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__msg__FleetState
    std::shared_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__msg__FleetState
    std::shared_ptr<aether_interfaces::msg::FleetState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FleetState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->drones != other.drones) {
      return false;
    }
    return true;
  }
  bool operator!=(const FleetState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FleetState_

// alias to use template instance with default allocator
using FleetState =
  aether_interfaces::msg::FleetState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__MSG__DETAIL__FLEET_STATE__STRUCT_HPP_
