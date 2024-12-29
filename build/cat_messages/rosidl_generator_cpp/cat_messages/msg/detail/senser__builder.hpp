// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__SENSER__BUILDER_HPP_
#define CAT_MESSAGES__MSG__DETAIL__SENSER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cat_messages/msg/detail/senser__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cat_messages
{

namespace msg
{

namespace builder
{

class Init_Senser_senser4
{
public:
  explicit Init_Senser_senser4(::cat_messages::msg::Senser & msg)
  : msg_(msg)
  {}
  ::cat_messages::msg::Senser senser4(::cat_messages::msg::Senser::_senser4_type arg)
  {
    msg_.senser4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cat_messages::msg::Senser msg_;
};

class Init_Senser_senser3
{
public:
  explicit Init_Senser_senser3(::cat_messages::msg::Senser & msg)
  : msg_(msg)
  {}
  Init_Senser_senser4 senser3(::cat_messages::msg::Senser::_senser3_type arg)
  {
    msg_.senser3 = std::move(arg);
    return Init_Senser_senser4(msg_);
  }

private:
  ::cat_messages::msg::Senser msg_;
};

class Init_Senser_senser2
{
public:
  explicit Init_Senser_senser2(::cat_messages::msg::Senser & msg)
  : msg_(msg)
  {}
  Init_Senser_senser3 senser2(::cat_messages::msg::Senser::_senser2_type arg)
  {
    msg_.senser2 = std::move(arg);
    return Init_Senser_senser3(msg_);
  }

private:
  ::cat_messages::msg::Senser msg_;
};

class Init_Senser_senser1
{
public:
  Init_Senser_senser1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Senser_senser2 senser1(::cat_messages::msg::Senser::_senser1_type arg)
  {
    msg_.senser1 = std::move(arg);
    return Init_Senser_senser2(msg_);
  }

private:
  ::cat_messages::msg::Senser msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cat_messages::msg::Senser>()
{
  return cat_messages::msg::builder::Init_Senser_senser1();
}

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__SENSER__BUILDER_HPP_
