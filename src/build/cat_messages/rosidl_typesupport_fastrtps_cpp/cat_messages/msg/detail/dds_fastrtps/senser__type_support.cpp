// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice
#include "cat_messages/msg/detail/senser__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cat_messages/msg/detail/senser__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace cat_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cat_messages
cdr_serialize(
  const cat_messages::msg::Senser & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: senser1
  cdr << ros_message.senser1;
  // Member: senser2
  cdr << ros_message.senser2;
  // Member: senser3
  cdr << ros_message.senser3;
  // Member: senser4
  cdr << ros_message.senser4;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cat_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cat_messages::msg::Senser & ros_message)
{
  // Member: senser1
  cdr >> ros_message.senser1;

  // Member: senser2
  cdr >> ros_message.senser2;

  // Member: senser3
  cdr >> ros_message.senser3;

  // Member: senser4
  cdr >> ros_message.senser4;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cat_messages
get_serialized_size(
  const cat_messages::msg::Senser & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: senser1
  {
    size_t item_size = sizeof(ros_message.senser1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: senser2
  {
    size_t item_size = sizeof(ros_message.senser2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: senser3
  {
    size_t item_size = sizeof(ros_message.senser3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: senser4
  {
    size_t item_size = sizeof(ros_message.senser4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cat_messages
max_serialized_size_Senser(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: senser1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: senser2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: senser3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: senser4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cat_messages::msg::Senser;
    is_plain =
      (
      offsetof(DataType, senser4) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Senser__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cat_messages::msg::Senser *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Senser__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cat_messages::msg::Senser *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Senser__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cat_messages::msg::Senser *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Senser__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Senser(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Senser__callbacks = {
  "cat_messages::msg",
  "Senser",
  _Senser__cdr_serialize,
  _Senser__cdr_deserialize,
  _Senser__get_serialized_size,
  _Senser__max_serialized_size
};

static rosidl_message_type_support_t _Senser__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Senser__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cat_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cat_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<cat_messages::msg::Senser>()
{
  return &cat_messages::msg::typesupport_fastrtps_cpp::_Senser__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cat_messages, msg, Senser)() {
  return &cat_messages::msg::typesupport_fastrtps_cpp::_Senser__handle;
}

#ifdef __cplusplus
}
#endif
