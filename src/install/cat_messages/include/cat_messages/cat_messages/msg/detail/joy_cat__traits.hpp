// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__JOY_CAT__TRAITS_HPP_
#define CAT_MESSAGES__MSG__DETAIL__JOY_CAT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cat_messages/msg/detail/joy_cat__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cat_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const JoyCat & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: buttun_1
  {
    out << "buttun_1: ";
    rosidl_generator_traits::value_to_yaml(msg.buttun_1, out);
    out << ", ";
  }

  // member: buttun_2
  {
    out << "buttun_2: ";
    rosidl_generator_traits::value_to_yaml(msg.buttun_2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JoyCat & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: buttun_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buttun_1: ";
    rosidl_generator_traits::value_to_yaml(msg.buttun_1, out);
    out << "\n";
  }

  // member: buttun_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buttun_2: ";
    rosidl_generator_traits::value_to_yaml(msg.buttun_2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JoyCat & msg, bool use_flow_style = false)
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
  const cat_messages::msg::JoyCat & msg,
  std::ostream & out, size_t indentation = 0)
{
  cat_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cat_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const cat_messages::msg::JoyCat & msg)
{
  return cat_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cat_messages::msg::JoyCat>()
{
  return "cat_messages::msg::JoyCat";
}

template<>
inline const char * name<cat_messages::msg::JoyCat>()
{
  return "cat_messages/msg/JoyCat";
}

template<>
struct has_fixed_size<cat_messages::msg::JoyCat>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cat_messages::msg::JoyCat>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cat_messages::msg::JoyCat>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAT_MESSAGES__MSG__DETAIL__JOY_CAT__TRAITS_HPP_
