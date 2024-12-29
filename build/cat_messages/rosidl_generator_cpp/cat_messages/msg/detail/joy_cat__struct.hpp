// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_HPP_
#define CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cat_messages__msg__JoyCat __attribute__((deprecated))
#else
# define DEPRECATED__cat_messages__msg__JoyCat __declspec(deprecated)
#endif

namespace cat_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JoyCat_
{
  using Type = JoyCat_<ContainerAllocator>;

  explicit JoyCat_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->yaw = 0.0;
      this->button_1 = false;
      this->button_2 = false;
    }
  }

  explicit JoyCat_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->yaw = 0.0;
      this->button_1 = false;
      this->button_2 = false;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _yaw_type =
    double;
  _yaw_type yaw;
  using _button_1_type =
    bool;
  _button_1_type button_1;
  using _button_2_type =
    bool;
  _button_2_type button_2;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__button_1(
    const bool & _arg)
  {
    this->button_1 = _arg;
    return *this;
  }
  Type & set__button_2(
    const bool & _arg)
  {
    this->button_2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cat_messages::msg::JoyCat_<ContainerAllocator> *;
  using ConstRawPtr =
    const cat_messages::msg::JoyCat_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cat_messages::msg::JoyCat_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cat_messages::msg::JoyCat_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::JoyCat_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::JoyCat_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::JoyCat_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::JoyCat_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cat_messages::msg::JoyCat_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cat_messages::msg::JoyCat_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cat_messages__msg__JoyCat
    std::shared_ptr<cat_messages::msg::JoyCat_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cat_messages__msg__JoyCat
    std::shared_ptr<cat_messages::msg::JoyCat_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JoyCat_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->button_1 != other.button_1) {
      return false;
    }
    if (this->button_2 != other.button_2) {
      return false;
    }
    return true;
  }
  bool operator!=(const JoyCat_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JoyCat_

// alias to use template instance with default allocator
using JoyCat =
  cat_messages::msg::JoyCat_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_HPP_
