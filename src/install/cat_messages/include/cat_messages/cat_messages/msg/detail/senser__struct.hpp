// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_HPP_
#define CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cat_messages__msg__Senser __attribute__((deprecated))
#else
# define DEPRECATED__cat_messages__msg__Senser __declspec(deprecated)
#endif

namespace cat_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Senser_
{
  using Type = Senser_<ContainerAllocator>;

  explicit Senser_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->senser1 = 0ll;
      this->senser2 = 0ll;
      this->senser3 = 0ll;
      this->senser4 = 0ll;
    }
  }

  explicit Senser_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->senser1 = 0ll;
      this->senser2 = 0ll;
      this->senser3 = 0ll;
      this->senser4 = 0ll;
    }
  }

  // field types and members
  using _senser1_type =
    int64_t;
  _senser1_type senser1;
  using _senser2_type =
    int64_t;
  _senser2_type senser2;
  using _senser3_type =
    int64_t;
  _senser3_type senser3;
  using _senser4_type =
    int64_t;
  _senser4_type senser4;

  // setters for named parameter idiom
  Type & set__senser1(
    const int64_t & _arg)
  {
    this->senser1 = _arg;
    return *this;
  }
  Type & set__senser2(
    const int64_t & _arg)
  {
    this->senser2 = _arg;
    return *this;
  }
  Type & set__senser3(
    const int64_t & _arg)
  {
    this->senser3 = _arg;
    return *this;
  }
  Type & set__senser4(
    const int64_t & _arg)
  {
    this->senser4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cat_messages::msg::Senser_<ContainerAllocator> *;
  using ConstRawPtr =
    const cat_messages::msg::Senser_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cat_messages::msg::Senser_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cat_messages::msg::Senser_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::Senser_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::Senser_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cat_messages::msg::Senser_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cat_messages::msg::Senser_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cat_messages::msg::Senser_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cat_messages::msg::Senser_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cat_messages__msg__Senser
    std::shared_ptr<cat_messages::msg::Senser_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cat_messages__msg__Senser
    std::shared_ptr<cat_messages::msg::Senser_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Senser_ & other) const
  {
    if (this->senser1 != other.senser1) {
      return false;
    }
    if (this->senser2 != other.senser2) {
      return false;
    }
    if (this->senser3 != other.senser3) {
      return false;
    }
    if (this->senser4 != other.senser4) {
      return false;
    }
    return true;
  }
  bool operator!=(const Senser_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Senser_

// alias to use template instance with default allocator
using Senser =
  cat_messages::msg::Senser_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_HPP_
