// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cat_messages/msg/detail/senser__rosidl_typesupport_introspection_c.h"
#include "cat_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cat_messages/msg/detail/senser__functions.h"
#include "cat_messages/msg/detail/senser__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cat_messages__msg__Senser__init(message_memory);
}

void cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_fini_function(void * message_memory)
{
  cat_messages__msg__Senser__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_member_array[4] = {
  {
    "senser1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__Senser, senser1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "senser2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__Senser, senser2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "senser3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__Senser, senser3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "senser4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cat_messages__msg__Senser, senser4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_members = {
  "cat_messages__msg",  // message namespace
  "Senser",  // message name
  4,  // number of fields
  sizeof(cat_messages__msg__Senser),
  cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_member_array,  // message members
  cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_init_function,  // function to initialize message memory (memory has to be allocated)
  cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_type_support_handle = {
  0,
  &cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cat_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cat_messages, msg, Senser)() {
  if (!cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_type_support_handle.typesupport_identifier) {
    cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cat_messages__msg__Senser__rosidl_typesupport_introspection_c__Senser_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
