// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_HPP_
#define CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cat_messages__msg__Vel __attribute__((deprecated))
#else
# define DEPRECATED__cat_messages__msg__Vel __declspec(deprecated)
#endif

namespace cat_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vel_
{
  using Type = Vel_<ContainerAllocator>;

  explicit Vel_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_x = 0.0;
      this->vel_y = 0.0;
      this->vel_yaw = 0.0;
      this->vel_wheel_right = 0.0;
      this->vel_wheel_left = 0.0;
    }
  }

  explicit Vel_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_x = 0.0;
      this->vel_y = 0.0;
      this->vel_yaw = 0.0;
      this->vel_wheel_right = 0.0;
      this->vel_wheel_left = 0.0;
    }
  }

  // field types and members
  using _vel_x_type =
    double;
  _vel_x_type vel_x;
  using _vel_y_type =
    double;
  _vel_y_type vel_y;
  using _vel_yaw_type =
    double;
  _vel_yaw_type vel_yaw;
  using _vel_wheel_right_type =
    double;
  _vel_wheel_right_type vel_wheel_right;
  using _vel_wheel_left_type =
    double;
  _vel_wheel_left_type vel_wheel_left;

  // setters for named parameter idiom
  Type & set__vel_x(
    const double & _arg)
  {
    this->vel_x = _arg;
    return *this;
  }
  Type & set__vel_y(
    const double & _arg)
  {
    this->vel_y = _arg;
    return *this;
  }
  Type & set__vel_yaw(
    const double & _arg)
  {
    this->vel_yaw = _arg;
    return *this;
  }
  Type & set__vel_wheel_right(
    const double & _arg)
  {
    this->vel_wheel_right = _arg;
    return *this;
  }
  Type & set__vel_wheel_left(
    const double & _arg)
  {
    this->vel_wheel_left = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cat_messages::msg::Vel_<ContainerAllocator> *;
  using ConstRawPtr =
    const cat_messages::msg::Vel_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cat_messages::msg::Vel_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cat_messages::msg::Vel_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::Vel_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::Vel_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::Vel_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::Vel_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cat_messages::msg::Vel_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cat_messages::msg::Vel_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cat_messages__msg__Vel
    std::shared_ptr<cat_messages::msg::Vel_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cat_messages__msg__Vel
    std::shared_ptr<cat_messages::msg::Vel_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vel_ & other) const
  {
    if (this->vel_x != other.vel_x) {
      return false;
    }
    if (this->vel_y != other.vel_y) {
      return false;
    }
    if (this->vel_yaw != other.vel_yaw) {
      return false;
    }
    if (this->vel_wheel_right != other.vel_wheel_right) {
      return false;
    }
    if (this->vel_wheel_left != other.vel_wheel_left) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vel_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vel_

// alias to use template instance with default allocator
using Vel =
  cat_messages::msg::Vel_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_HPP_
