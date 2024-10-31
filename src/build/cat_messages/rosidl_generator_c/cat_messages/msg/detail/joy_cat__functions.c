// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cat_messages:msg/JoyCat.idl
// generated code does not contain a copyright notice
#include "cat_messages/msg/detail/joy_cat__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cat_messages__msg__JoyCat__init(cat_messages__msg__JoyCat * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // yaw
  // buttun_1
  // buttun_2
  return true;
}

void
cat_messages__msg__JoyCat__fini(cat_messages__msg__JoyCat * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // yaw
  // buttun_1
  // buttun_2
}

bool
cat_messages__msg__JoyCat__are_equal(const cat_messages__msg__JoyCat * lhs, const cat_messages__msg__JoyCat * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // buttun_1
  if (lhs->buttun_1 != rhs->buttun_1) {
    return false;
  }
  // buttun_2
  if (lhs->buttun_2 != rhs->buttun_2) {
    return false;
  }
  return true;
}

bool
cat_messages__msg__JoyCat__copy(
  const cat_messages__msg__JoyCat * input,
  cat_messages__msg__JoyCat * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // yaw
  output->yaw = input->yaw;
  // buttun_1
  output->buttun_1 = input->buttun_1;
  // buttun_2
  output->buttun_2 = input->buttun_2;
  return true;
}

cat_messages__msg__JoyCat *
cat_messages__msg__JoyCat__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__JoyCat * msg = (cat_messages__msg__JoyCat *)allocator.allocate(sizeof(cat_messages__msg__JoyCat), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cat_messages__msg__JoyCat));
  bool success = cat_messages__msg__JoyCat__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cat_messages__msg__JoyCat__destroy(cat_messages__msg__JoyCat * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cat_messages__msg__JoyCat__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cat_messages__msg__JoyCat__Sequence__init(cat_messages__msg__JoyCat__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__JoyCat * data = NULL;

  if (size) {
    data = (cat_messages__msg__JoyCat *)allocator.zero_allocate(size, sizeof(cat_messages__msg__JoyCat), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cat_messages__msg__JoyCat__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cat_messages__msg__JoyCat__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cat_messages__msg__JoyCat__Sequence__fini(cat_messages__msg__JoyCat__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cat_messages__msg__JoyCat__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cat_messages__msg__JoyCat__Sequence *
cat_messages__msg__JoyCat__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__JoyCat__Sequence * array = (cat_messages__msg__JoyCat__Sequence *)allocator.allocate(sizeof(cat_messages__msg__JoyCat__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cat_messages__msg__JoyCat__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cat_messages__msg__JoyCat__Sequence__destroy(cat_messages__msg__JoyCat__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cat_messages__msg__JoyCat__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cat_messages__msg__JoyCat__Sequence__are_equal(const cat_messages__msg__JoyCat__Sequence * lhs, const cat_messages__msg__JoyCat__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cat_messages__msg__JoyCat__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cat_messages__msg__JoyCat__Sequence__copy(
  const cat_messages__msg__JoyCat__Sequence * input,
  cat_messages__msg__JoyCat__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cat_messages__msg__JoyCat);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cat_messages__msg__JoyCat * data =
      (cat_messages__msg__JoyCat *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cat_messages__msg__JoyCat__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cat_messages__msg__JoyCat__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cat_messages__msg__JoyCat__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
