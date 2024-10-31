// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__JOY_CAT__FUNCTIONS_H_
#define CAT_MESSAGES__MSG__DETAIL__JOY_CAT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cat_messages/msg/rosidl_generator_c__visibility_control.h"

#include "cat_messages/msg/detail/joy_cat__struct.h"

/// Initialize msg/JoyCat message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cat_messages__msg__JoyCat
 * )) before or use
 * cat_messages__msg__JoyCat__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__init(cat_messages__msg__JoyCat * msg);

/// Finalize msg/JoyCat message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__JoyCat__fini(cat_messages__msg__JoyCat * msg);

/// Create msg/JoyCat message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cat_messages__msg__JoyCat__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
cat_messages__msg__JoyCat *
cat_messages__msg__JoyCat__create();

/// Destroy msg/JoyCat message.
/**
 * It calls
 * cat_messages__msg__JoyCat__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__JoyCat__destroy(cat_messages__msg__JoyCat * msg);

/// Check for msg/JoyCat message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__are_equal(const cat_messages__msg__JoyCat * lhs, const cat_messages__msg__JoyCat * rhs);

/// Copy a msg/JoyCat message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__copy(
  const cat_messages__msg__JoyCat * input,
  cat_messages__msg__JoyCat * output);

/// Initialize array of msg/JoyCat messages.
/**
 * It allocates the memory for the number of elements and calls
 * cat_messages__msg__JoyCat__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__Sequence__init(cat_messages__msg__JoyCat__Sequence * array, size_t size);

/// Finalize array of msg/JoyCat messages.
/**
 * It calls
 * cat_messages__msg__JoyCat__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__JoyCat__Sequence__fini(cat_messages__msg__JoyCat__Sequence * array);

/// Create array of msg/JoyCat messages.
/**
 * It allocates the memory for the array and calls
 * cat_messages__msg__JoyCat__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
cat_messages__msg__JoyCat__Sequence *
cat_messages__msg__JoyCat__Sequence__create(size_t size);

/// Destroy array of msg/JoyCat messages.
/**
 * It calls
 * cat_messages__msg__JoyCat__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__JoyCat__Sequence__destroy(cat_messages__msg__JoyCat__Sequence * array);

/// Check for msg/JoyCat message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__Sequence__are_equal(const cat_messages__msg__JoyCat__Sequence * lhs, const cat_messages__msg__JoyCat__Sequence * rhs);

/// Copy an array of msg/JoyCat messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__JoyCat__Sequence__copy(
  const cat_messages__msg__JoyCat__Sequence * input,
  cat_messages__msg__JoyCat__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAT_MESSAGES__MSG__DETAIL__JOY_CAT__FUNCTIONS_H_
