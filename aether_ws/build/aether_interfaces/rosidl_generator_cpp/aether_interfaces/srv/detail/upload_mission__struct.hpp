// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from aether_interfaces:srv/UploadMission.idl
// generated code does not contain a copyright notice

#ifndef AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__STRUCT_HPP_
#define AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__srv__UploadMission_Request __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__srv__UploadMission_Request __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UploadMission_Request_
{
  using Type = UploadMission_Request_<ContainerAllocator>;

  explicit UploadMission_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->file_path = "";
      this->target_system_id = 0;
    }
  }

  explicit UploadMission_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : file_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->file_path = "";
      this->target_system_id = 0;
    }
  }

  // field types and members
  using _file_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _file_path_type file_path;
  using _target_system_id_type =
    uint8_t;
  _target_system_id_type target_system_id;

  // setters for named parameter idiom
  Type & set__file_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->file_path = _arg;
    return *this;
  }
  Type & set__target_system_id(
    const uint8_t & _arg)
  {
    this->target_system_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__srv__UploadMission_Request
    std::shared_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__srv__UploadMission_Request
    std::shared_ptr<aether_interfaces::srv::UploadMission_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UploadMission_Request_ & other) const
  {
    if (this->file_path != other.file_path) {
      return false;
    }
    if (this->target_system_id != other.target_system_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const UploadMission_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UploadMission_Request_

// alias to use template instance with default allocator
using UploadMission_Request =
  aether_interfaces::srv::UploadMission_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aether_interfaces


#ifndef _WIN32
# define DEPRECATED__aether_interfaces__srv__UploadMission_Response __attribute__((deprecated))
#else
# define DEPRECATED__aether_interfaces__srv__UploadMission_Response __declspec(deprecated)
#endif

namespace aether_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UploadMission_Response_
{
  using Type = UploadMission_Response_<ContainerAllocator>;

  explicit UploadMission_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit UploadMission_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__aether_interfaces__srv__UploadMission_Response
    std::shared_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__aether_interfaces__srv__UploadMission_Response
    std::shared_ptr<aether_interfaces::srv::UploadMission_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UploadMission_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const UploadMission_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UploadMission_Response_

// alias to use template instance with default allocator
using UploadMission_Response =
  aether_interfaces::srv::UploadMission_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace aether_interfaces

namespace aether_interfaces
{

namespace srv
{

struct UploadMission
{
  using Request = aether_interfaces::srv::UploadMission_Request;
  using Response = aether_interfaces::srv::UploadMission_Response;
};

}  // namespace srv

}  // namespace aether_interfaces

#endif  // AETHER_INTERFACES__SRV__DETAIL__UPLOAD_MISSION__STRUCT_HPP_
