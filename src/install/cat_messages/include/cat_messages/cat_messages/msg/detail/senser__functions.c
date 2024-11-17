// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cat_messages:msg/Senser.idl
// generated code does not contain a copyright notice
#include "cat_messages/msg/detail/senser__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cat_messages__msg__Senser__init(cat_messages__msg__Senser * msg)
{
  if (!msg) {
    return false;
  }
  // senser1
  // senser2
  // senser3
  // senser4
  return true;
}

void
cat_messages__msg__Senser__fini(cat_messages__msg__Senser * msg)
{
  if (!msg) {
    return;
  }
  // senser1
  // senser2
  // senser3
  // senser4
}

bool
cat_messages__msg__Senser__are_equal(const cat_messages__msg__Senser * lhs, const cat_messages__msg__Senser * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // senser1
  if (lhs->senser1 != rhs->senser1) {
    return false;
  }
  // senser2
  if (lhs->senser2 != rhs->senser2) {
    return false;
  }
  // senser3
  if (lhs->senser3 != rhs->senser3) {
    return false;
  }
  // senser4
  if (lhs->senser4 != rhs->senser4) {
    return false;
  }
  return true;
}

bool
cat_messages__msg__Senser__copy(
  const cat_messages__msg__Senser * input,
  cat_messages__msg__Senser * output)
{
  if (!input || !output) {
    return false;
  }
  // senser1
  output->senser1 = input->senser1;
  // senser2
  output->senser2 = input->senser2;
  // senser3
  output->senser3 = input->senser3;
  // senser4
  output->senser4 = input->senser4;
  return true;
}

cat_messages__msg__Senser *
cat_messages__msg__Senser__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Senser * msg = (cat_messages__msg__Senser *)allocator.allocate(sizeof(cat_messages__msg__Senser), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cat_messages__msg__Senser));
  bool success = cat_messages__msg__Senser__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cat_messages__msg__Senser__destroy(cat_messages__msg__Senser * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cat_messages__msg__Senser__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cat_messages__msg__Senser__Sequence__init(cat_messages__msg__Senser__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Senser * data = NULL;

  if (size) {
    data = (cat_messages__msg__Senser *)allocator.zero_allocate(size, sizeof(cat_messages__msg__Senser), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cat_messages__msg__Senser__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cat_messages__msg__Senser__fini(&data[i - 1]);
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
cat_messages__msg__Senser__Sequence__fini(cat_messages__msg__Senser__Sequence * array)
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
      cat_messages__msg__Senser__fini(&array->data[i]);
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

cat_messages__msg__Senser__Sequence *
cat_messages__msg__Senser__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cat_messages__msg__Senser__Sequence * array = (cat_messages__msg__Senser__Sequence *)allocator.allocate(sizeof(cat_messages__msg__Senser__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cat_messages__msg__Senser__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cat_messages__msg__Senser__Sequence__destroy(cat_messages__msg__Senser__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cat_messages__msg__Senser__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cat_messages__msg__Senser__Sequence__are_equal(const cat_messages__msg__Senser__Sequence * lhs, const cat_messages__msg__Senser__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cat_messages__msg__Senser__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cat_messages__msg__Senser__Sequence__copy(
  const cat_messages__msg__Senser__Sequence * input,
  cat_messages__msg__Senser__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cat_messages__msg__Senser);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cat_messages__msg__Senser * data =
      (cat_messages__msg__Senser *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cat_messages__msg__Senser__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cat_messages__msg__Senser__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cat_messages__msg__Senser__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
