// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "cat_messages/msg/detail/senser__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace cat_messages
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _Senser_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Senser_type_support_ids_t;

static const _Senser_type_support_ids_t _Senser_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Senser_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Senser_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Senser_type_support_symbol_names_t _Senser_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cat_messages, msg, Senser)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cat_messages, msg, Senser)),
  }
};

typedef struct _Senser_type_support_data_t
{
  void * data[2];
} _Senser_type_support_data_t;

static _Senser_type_support_data_t _Senser_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Senser_message_typesupport_map = {
  2,
  "cat_messages",
  &_Senser_message_typesupport_ids.typesupport_identifier[0],
  &_Senser_message_typesupport_symbol_names.symbol_name[0],
  &_Senser_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Senser_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Senser_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace cat_messages

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cat_messages::msg::Senser>()
{
  return &::cat_messages::msg::rosidl_typesupport_cpp::Senser_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, cat_messages, msg, Senser)() {
  return get_message_type_support_handle<cat_messages::msg::Senser>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
