// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:srv/StartCalibration.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_HPP_
#define AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__srv__StartCalibration_Request __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__srv__StartCalibration_Request __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartCalibration_Request_
{
  using Type = StartCalibration_Request_<ContainerAllocator>;

  explicit StartCalibration_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_system_id = 0;
      this->sensor_type = "";
    }
  }

  explicit StartCalibration_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_system_id = 0;
      this->sensor_type = "";
    }
  }

  // field types and members
  using _target_system_id_type =
    uint8_t;
  _target_system_id_type target_system_id;
  using _sensor_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sensor_type_type sensor_type;

  // setters for named parameter idiom
  Type & set__target_system_id(
    const uint8_t & _arg)
  {
    this->target_system_id = _arg;
    return *this;
  }
  Type & set__sensor_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sensor_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__srv__StartCalibration_Request
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__srv__StartCalibration_Request
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartCalibration_Request_ & other) const
  {
    if (this->target_system_id != other.target_system_id) {
      return false;
    }
    if (this->sensor_type != other.sensor_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartCalibration_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartCalibration_Request_

// alias to use template instance with default allocator
using StartCalibration_Request =
  aether_interfaces::srv::StartCalibration_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aether_interfaces


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__srv__StartCalibration_Response __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__srv__StartCalibration_Response __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartCalibration_Response_
{
  using Type = StartCalibration_Response_<ContainerAllocator>;

  explicit StartCalibration_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit StartCalibration_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__srv__StartCalibration_Response
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__srv__StartCalibration_Response
    std::shared_ptr<aether_interfaces::srv::StartCalibration_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartCalibration_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartCalibration_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartCalibration_Response_

// alias to use template instance with default allocator
using StartCalibration_Response =
  aether_interfaces::srv::StartCalibration_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aether_interfaces

namespace aether_interfaces
{

namespace srv
{

struct StartCalibration
{
  using Request = aether_interfaces::srv::StartCalibration_Request;
  using Response = aether_interfaces::srv::StartCalibration_Response;
};

}  // namespace srv

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__SRV__DETAIL__START_CALIBRATION__STRUCT_HPP_
