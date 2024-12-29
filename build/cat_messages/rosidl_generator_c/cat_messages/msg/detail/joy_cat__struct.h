// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_H_
#define CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/JoyCat in the package cat_messages.
typedef struct cat_messages__msg__JoyCat
{
  double x;
  double yaw;
  bool button_1;
  bool button_2;
} cat_messages__msg__JoyCat;

// Struct for a sequence of cat_messages__msg__JoyCat.
typedef struct cat_messages__msg__JoyCat__Sequence
{
  cat_messages__msg__JoyCat * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cat_messages__msg__JoyCat__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAT_MESSAGES__MSG__DETAIL__JOY_CAT__STRUCT_H_
