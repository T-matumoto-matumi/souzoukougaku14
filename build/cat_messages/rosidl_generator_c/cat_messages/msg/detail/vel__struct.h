// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_H_
#define CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Vel in the package cat_messages.
typedef struct cat_messages__msg__Vel
{
  double vel_x;
  double vel_y;
  double vel_yaw;
  double vel_wheel_right;
  double vel_wheel_left;
} cat_messages__msg__Vel;

// Struct for a sequence of cat_messages__msg__Vel.
typedef struct cat_messages__msg__Vel__Sequence
{
  cat_messages__msg__Vel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cat_messages__msg__Vel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAT_MESSAGES__MSG__DETAIL__VEL__STRUCT_H_
