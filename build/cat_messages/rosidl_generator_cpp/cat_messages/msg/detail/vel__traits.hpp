// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__VEL__TRAITS_HPP_
#define CAT_MESSAGES__MSG__DETAIL__VEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cat_messages/msg/detail/vel__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cat_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const Vel & msg,
  std::ostream & out)
{
  out << "{";
  // member: vel_x
  {
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << ", ";
  }

  // member: vel_y
  {
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << ", ";
  }

  // member: vel_yaw
  {
    out << "vel_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_yaw, out);
    out << ", ";
  }

  // member: vel_wheel_right
  {
    out << "vel_wheel_right: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_wheel_right, out);
    out << ", ";
  }

  // member: vel_wheel_left
  {
    out << "vel_wheel_left: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_wheel_left, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Vel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vel_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_x: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_x, out);
    out << "\n";
  }

  // member: vel_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_y: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_y, out);
    out << "\n";
  }

  // member: vel_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_yaw, out);
    out << "\n";
  }

  // member: vel_wheel_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_wheel_right: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_wheel_right, out);
    out << "\n";
  }

  // member: vel_wheel_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_wheel_left: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_wheel_left, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Vel & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cat_messages

namespace rosidl_generator_traits
{

[[deprecated("use cat_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cat_messages::msg::Vel & msg,
  std::ostream & out, size_t indentation = 0)
{
  cat_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cat_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const cat_messages::msg::Vel & msg)
{
  return cat_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cat_messages::msg::Vel>()
{
  return "cat_messages::msg::Vel";
}

template<>
inline const char * name<cat_messages::msg::Vel>()
{
  return "cat_messages/msg/Vel";
}

template<>
struct has_fixed_size<cat_messages::msg::Vel>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cat_messages::msg::Vel>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cat_messages::msg::Vel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAT_MESSAGES__MSG__DETAIL__VEL__TRAITS_HPP_
