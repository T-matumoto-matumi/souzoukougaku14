// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice

#ifndef CAT_MESSAGES__MSG__DETAIL__SENSER__FUNCTIONS_H_
#define CAT_MESSAGES__MSG__DETAIL__SENSER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cat_messages/msg/rosidl_generator_c__visibility_control.h"

#include "cat_messages/msg/detail/senser__struct.h"

/// Initialize msg/Senser message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cat_messages__msg__Senser
 * )) before or use
 * cat_messages__msg__Senser__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__Senser__init(cat_messages__msg__Senser * msg);

/// Finalize msg/Senser message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__Senser__fini(cat_messages__msg__Senser * msg);

/// Create msg/Senser message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cat_messages__msg__Senser__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
cat_messages__msg__Senser *
cat_messages__msg__Senser__create();

/// Destroy msg/Senser message.
/**
 * It calls
 * cat_messages__msg__Senser__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__Senser__destroy(cat_messages__msg__Senser * msg);

/// Check for msg/Senser message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__Senser__are_equal(const cat_messages__msg__Senser * lhs, const cat_messages__msg__Senser * rhs);

/// Copy a msg/Senser message.
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
cat_messages__msg__Senser__copy(
  const cat_messages__msg__Senser * input,
  cat_messages__msg__Senser * output);

/// Initialize array of msg/Senser messages.
/**
 * It allocates the memory for the number of elements and calls
 * cat_messages__msg__Senser__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__Senser__Sequence__init(cat_messages__msg__Senser__Sequence * array, size_t size);

/// Finalize array of msg/Senser messages.
/**
 * It calls
 * cat_messages__msg__Senser__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__Senser__Sequence__fini(cat_messages__msg__Senser__Sequence * array);

/// Create array of msg/Senser messages.
/**
 * It allocates the memory for the array and calls
 * cat_messages__msg__Senser__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
cat_messages__msg__Senser__Sequence *
cat_messages__msg__Senser__Sequence__create(size_t size);

/// Destroy array of msg/Senser messages.
/**
 * It calls
 * cat_messages__msg__Senser__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
void
cat_messages__msg__Senser__Sequence__destroy(cat_messages__msg__Senser__Sequence * array);

/// Check for msg/Senser message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cat_messages
bool
cat_messages__msg__Senser__Sequence__are_equal(const cat_messages__msg__Senser__Sequence * lhs, const cat_messages__msg__Senser__Sequence * rhs);

/// Copy an array of msg/Senser messages.
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
cat_messages__msg__Senser__Sequence__copy(
  const cat_messages__msg__Senser__Sequence * input,
  cat_messages__msg__Senser__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAT_MESSAGES__MSG__DETAIL__SENSER__FUNCTIONS_H_