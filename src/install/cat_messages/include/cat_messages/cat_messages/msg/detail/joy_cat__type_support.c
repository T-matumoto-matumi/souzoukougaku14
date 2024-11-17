// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cat_messages/msg/detail/joy_cat__rosidl_typesupport_introspection_c.h"
#include "cat_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cat_messages/msg/detail/joy_cat__functions.h"
#include "cat_messages/msg/detail/joy_cat__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cat_messages__msg__JoyCat__init(message_memory);
}

void cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_fini_function(void * message_memory)
{
  cat_messages__msg__JoyCat__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__JoyCat, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__JoyCat, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "buttun_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__JoyCat, buttun_1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "buttun_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__JoyCat, buttun_2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_members = {
  "cat_messages__msg",  // message namespace
  "JoyCat",  // message name
  4,  // number of fields
  sizeof(cat_messages__msg__JoyCat),
  cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_member_array,  // message members
  cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_init_function,  // function to initialize message memory (memory has to be allocated)
  cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_type_support_handle = {
  0,
  &cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cat_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cat_messages, msg, JoyCat)() {
  if (!cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_type_support_handle.typesupport_identifier) {
    cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cat_messages__msg__JoyCat__rosidl_typesupport_introspection_c__JoyCat_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
