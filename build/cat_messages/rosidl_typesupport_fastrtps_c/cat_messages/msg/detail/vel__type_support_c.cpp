// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice
#include "cat_messages/msg/detail/vel__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "cat_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cat_messages/msg/detail/vel__struct.h"
#include "cat_messages/msg/detail/vel__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Vel__ros_msg_type = cat_messages__msg__Vel;

static bool _Vel__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Vel__ros_msg_type * ros_message = static_cast<const _Vel__ros_msg_type *>(untyped_ros_message);
  // Field name: vel_x
  {
    cdr << ros_message->vel_x;
  }

  // Field name: vel_y
  {
    cdr << ros_message->vel_y;
  }

  // Field name: vel_yaw
  {
    cdr << ros_message->vel_yaw;
  }

  // Field name: vel_wheel_right
  {
    cdr << ros_message->vel_wheel_right;
  }

  // Field name: vel_wheel_left
  {
    cdr << ros_message->vel_wheel_left;
  }

  return true;
}

static bool _Vel__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Vel__ros_msg_type * ros_message = static_cast<_Vel__ros_msg_type *>(untyped_ros_message);
  // Field name: vel_x
  {
    cdr >> ros_message->vel_x;
  }

  // Field name: vel_y
  {
    cdr >> ros_message->vel_y;
  }

  // Field name: vel_yaw
  {
    cdr >> ros_message->vel_yaw;
  }

  // Field name: vel_wheel_right
  {
    cdr >> ros_message->vel_wheel_right;
  }

  // Field name: vel_wheel_left
  {
    cdr >> ros_message->vel_wheel_left;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cat_messages
size_t get_serialized_size_cat_messages__msg__Vel(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Vel__ros_msg_type * ros_message = static_cast<const _Vel__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name vel_x
  {
    size_t item_size = sizeof(ros_message->vel_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_y
  {
    size_t item_size = sizeof(ros_message->vel_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_yaw
  {
    size_t item_size = sizeof(ros_message->vel_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_wheel_right
  {
    size_t item_size = sizeof(ros_message->vel_wheel_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_wheel_left
  {
    size_t item_size = sizeof(ros_message->vel_wheel_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Vel__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_cat_messages__msg__Vel(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cat_messages
size_t max_serialized_size_cat_messages__msg__Vel(
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

  // member: vel_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_wheel_right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: vel_wheel_left
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
    using DataType = cat_messages__msg__Vel;
    is_plain =
      (
      offsetof(DataType, vel_wheel_left) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Vel__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_cat_messages__msg__Vel(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Vel = {
  "cat_messages::msg",
  "Vel",
  _Vel__cdr_serialize,
  _Vel__cdr_deserialize,
  _Vel__get_serialized_size,
  _Vel__max_serialized_size
};

static rosidl_message_type_support_t _Vel__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Vel,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cat_messages, msg, Vel)() {
  return &_Vel__type_support;
}

#if defined(__cplusplus)
}
#endif
