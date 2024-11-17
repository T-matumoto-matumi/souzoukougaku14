// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__JOY_CAT__BUILDER_HPP_
#define CAT_MESSAGES__MSG__DETAIL__JOY_CAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cat_messages/msg/detail/joy_cat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cat_messages
{

namespace msg
{

namespace builder
{

class Init_JoyCat_buttun_2
{
public:
  explicit Init_JoyCat_buttun_2(::cat_messages::msg::JoyCat & msg)
  : msg_(msg)
  {}
  ::cat_messages::msg::JoyCat buttun_2(::cat_messages::msg::JoyCat::_buttun_2_type arg)
  {
    msg_.buttun_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cat_messages::msg::JoyCat msg_;
};

class Init_JoyCat_buttun_1
{
public:
  explicit Init_JoyCat_buttun_1(::cat_messages::msg::JoyCat & msg)
  : msg_(msg)
  {}
  Init_JoyCat_buttun_2 buttun_1(::cat_messages::msg::JoyCat::_buttun_1_type arg)
  {
    msg_.buttun_1 = std::move(arg);
    return Init_JoyCat_buttun_2(msg_);
  }

private:
  ::cat_messages::msg::JoyCat msg_;
};

class Init_JoyCat_yaw
{
public:
  explicit Init_JoyCat_yaw(::cat_messages::msg::JoyCat & msg)
  : msg_(msg)
  {}
  Init_JoyCat_buttun_1 yaw(::cat_messages::msg::JoyCat::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_JoyCat_buttun_1(msg_);
  }

private:
  ::cat_messages::msg::JoyCat msg_;
};

class Init_JoyCat_x
{
public:
  Init_JoyCat_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoyCat_yaw x(::cat_messages::msg::JoyCat::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_JoyCat_yaw(msg_);
  }

private:
  ::cat_messages::msg::JoyCat msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cat_messages::msg::JoyCat>()
{
  return cat_messages::msg::builder::Init_JoyCat_x();
}

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__JOY_CAT__BUILDER_HPP_
