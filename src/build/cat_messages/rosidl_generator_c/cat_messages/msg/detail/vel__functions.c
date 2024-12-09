// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cat_messages:msg/Vel.idl
// generated code does not contain a copyright notice
#include "cat_messages/msg/detail/vel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cat_messages__msg__Vel__init(cat_messages__msg__Vel * msg)
{
  if (!msg) {
    return false;
  }
  // vel_x
  // vel_y
  // vel_yaw
  // vel_wheel_right
  // vel_wheel_left
  return true;
}

void
cat_messages__msg__Vel__fini(cat_messages__msg__Vel * msg)
{
  if (!msg) {
    return;
  }
  // vel_x
  // vel_y
  // vel_yaw
  // vel_wheel_right
  // vel_wheel_left
}

bool
cat_messages__msg__Vel__are_equal(const cat_messages__msg__Vel * lhs, const cat_messages__msg__Vel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vel_x
  if (lhs->vel_x != rhs->vel_x) {
    return false;
  }
  // vel_y
  if (lhs->vel_y != rhs->vel_y) {
    return false;
  }
  // vel_yaw
  if (lhs->vel_yaw != rhs->vel_yaw) {
    return false;
  }
  // vel_wheel_right
  if (lhs->vel_wheel_right != rhs->vel_wheel_right) {
    return false;
  }
  // vel_wheel_left
  if (lhs->vel_wheel_left != rhs->vel_wheel_left) {
    return false;
  }
  return true;
}

bool
cat_messages__msg__Vel__copy(
  const cat_messages__msg__Vel * input,
  cat_messages__msg__Vel * output)
{
  if (!input || !output) {
    return false;
  }
  // vel_x
  output->vel_x = input->vel_x;
  // vel_y
  output->vel_y = input->vel_y;
  // vel_yaw
  output->vel_yaw = input->vel_yaw;
  // vel_wheel_right
  output->vel_wheel_right = input->vel_wheel_right;
  // vel_wheel_left
  output->vel_wheel_left = input->vel_wheel_left;
  return true;
}

cat_messages__msg__Vel *
cat_messages__msg__Vel__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Vel * msg = (cat_messages__msg__Vel *)allocator.allocate(sizeof(cat_messages__msg__Vel), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cat_messages__msg__Vel));
  bool success = cat_messages__msg__Vel__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cat_messages__msg__Vel__destroy(cat_messages__msg__Vel * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cat_messages__msg__Vel__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cat_messages__msg__Vel__Sequence__init(cat_messages__msg__Vel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Vel * data = NULL;

  if (size) {
    data = (cat_messages__msg__Vel *)allocator.zero_allocate(size, sizeof(cat_messages__msg__Vel), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cat_messages__msg__Vel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cat_messages__msg__Vel__fini(&data[i - 1]);
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
cat_messages__msg__Vel__Sequence__fini(cat_messages__msg__Vel__Sequence * array)
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
      cat_messages__msg__Vel__fini(&array->data[i]);
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

cat_messages__msg__Vel__Sequence *
cat_messages__msg__Vel__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Vel__Sequence * array = (cat_messages__msg__Vel__Sequence *)allocator.allocate(sizeof(cat_messages__msg__Vel__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cat_messages__msg__Vel__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cat_messages__msg__Vel__Sequence__destroy(cat_messages__msg__Vel__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cat_messages__msg__Vel__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cat_messages__msg__Vel__Sequence__are_equal(const cat_messages__msg__Vel__Sequence * lhs, const cat_messages__msg__Vel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cat_messages__msg__Vel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cat_messages__msg__Vel__Sequence__copy(
  const cat_messages__msg__Vel__Sequence * input,
  cat_messages__msg__Vel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cat_messages__msg__Vel);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cat_messages__msg__Vel * data =
      (cat_messages__msg__Vel *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cat_messages__msg__Vel__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cat_messages__msg__Vel__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cat_messages__msg__Vel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
