// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__VEL__BUILDER_HPP_
#define CAT_MESSAGES__MSG__DETAIL__VEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cat_messages/msg/detail/vel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cat_messages
{

namespace msg
{

namespace builder
{

class Init_Vel_vel_wheel_left
{
public:
  explicit Init_Vel_vel_wheel_left(::cat_messages::msg::Vel & msg)
  : msg_(msg)
  {}
  ::cat_messages::msg::Vel vel_wheel_left(::cat_messages::msg::Vel::_vel_wheel_left_type arg)
  {
    msg_.vel_wheel_left = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cat_messages::msg::Vel msg_;
};

class Init_Vel_vel_wheel_right
{
public:
  explicit Init_Vel_vel_wheel_right(::cat_messages::msg::Vel & msg)
  : msg_(msg)
  {}
  Init_Vel_vel_wheel_left vel_wheel_right(::cat_messages::msg::Vel::_vel_wheel_right_type arg)
  {
    msg_.vel_wheel_right = std::move(arg);
    return Init_Vel_vel_wheel_left(msg_);
  }

private:
  ::cat_messages::msg::Vel msg_;
};

class Init_Vel_vel_yaw
{
public:
  explicit Init_Vel_vel_yaw(::cat_messages::msg::Vel & msg)
  : msg_(msg)
  {}
  Init_Vel_vel_wheel_right vel_yaw(::cat_messages::msg::Vel::_vel_yaw_type arg)
  {
    msg_.vel_yaw = std::move(arg);
    return Init_Vel_vel_wheel_right(msg_);
  }

private:
  ::cat_messages::msg::Vel msg_;
};

class Init_Vel_vel_y
{
public:
  explicit Init_Vel_vel_y(::cat_messages::msg::Vel & msg)
  : msg_(msg)
  {}
  Init_Vel_vel_yaw vel_y(::cat_messages::msg::Vel::_vel_y_type arg)
  {
    msg_.vel_y = std::move(arg);
    return Init_Vel_vel_yaw(msg_);
  }

private:
  ::cat_messages::msg::Vel msg_;
};

class Init_Vel_vel_x
{
public:
  Init_Vel_vel_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vel_vel_y vel_x(::cat_messages::msg::Vel::_vel_x_type arg)
  {
    msg_.vel_x = std::move(arg);
    return Init_Vel_vel_y(msg_);
  }

private:
  ::cat_messages::msg::Vel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cat_messages::msg::Vel>()
{
  return cat_messages::msg::builder::Init_Vel_vel_x();
}

}  // namespace cat_messages

#endif  // CAT_MESSAGES__MSG__DETAIL__VEL__BUILDER_HPP_
