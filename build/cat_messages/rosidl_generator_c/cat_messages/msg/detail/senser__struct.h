// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_H_
#define CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Senser in the package cat_messages.
typedef struct cat_messages__msg__Senser
{
  int64_t senser1;
  int64_t senser2;
  int64_t senser3;
  int64_t senser4;
} cat_messages__msg__Senser;

// Struct for a sequence of cat_messages__msg__Senser.
typedef struct cat_messages__msg__Senser__Sequence
{
  cat_messages__msg__Senser * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cat_messages__msg__Senser__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAT_MESSAGES__MSG__DETAIL__SENSER__STRUCT_H_
