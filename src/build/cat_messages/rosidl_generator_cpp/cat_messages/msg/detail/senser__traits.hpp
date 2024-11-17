// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__SENSER__TRAITS_HPP_
#define CAT_MESSAGES__MSG__DETAIL__SENSER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cat_messages/msg/detail/senser__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cat_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const Senser & msg,
  std::ostream & out)
{
  out << "{";
  // member: senser1
  {
    out << "senser1: ";
    rosidl_generator_traits::value_to_yaml(msg.senser1, out);
    out << ", ";
  }

  // member: senser2
  {
    out << "senser2: ";
    rosidl_generator_traits::value_to_yaml(msg.senser2, out);
    out << ", ";
  }

  // member: senser3
  {
    out << "senser3: ";
    rosidl_generator_traits::value_to_yaml(msg.senser3, out);
    out << ", ";
  }

  // member: senser4
  {
    out << "senser4: ";
    rosidl_generator_traits::value_to_yaml(msg.senser4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Senser & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: senser1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "senser1: ";
    rosidl_generator_traits::value_to_yaml(msg.senser1, out);
    out << "\n";
  }

  // member: senser2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "senser2: ";
    rosidl_generator_traits::value_to_yaml(msg.senser2, out);
    out << "\n";
  }

  // member: senser3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "senser3: ";
    rosidl_generator_traits::value_to_yaml(msg.senser3, out);
    out << "\n";
  }

  // member: senser4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "senser4: ";
    rosidl_generator_traits::value_to_yaml(msg.senser4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Senser & msg, bool use_flow_style = false)
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
  const cat_messages::msg::Senser & msg,
  std::ostream & out, size_t indentation = 0)
{
  cat_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cat_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const cat_messages::msg::Senser & msg)
{
  return cat_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cat_messages::msg::Senser>()
{
  return "cat_messages::msg::Senser";
}

template<>
inline const char * name<cat_messages::msg::Senser>()
{
  return "cat_messages/msg/Senser";
}

template<>
struct has_fixed_size<cat_messages::msg::Senser>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cat_messages::msg::Senser>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cat_messages::msg::Senser>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAT_MESSAGES__MSG__DETAIL__SENSER__TRAITS_HPP_
