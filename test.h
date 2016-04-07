#pragma once

#include <stdio.h>

typedef int (test_fn_t)(void);

struct test_t {
  char * name;
  char * group;
  test_fn_t * fn;
};

int __test_count;
struct test_t __test_cache[10000];

#define TEST(group_name, test_name) \
  int __impl__##group_name##__##test_name##__(); \
  void __attribute__ ((constructor)) __##group_name##__##test_name##__() { \
        struct test_t new_test; \
        new_test.name = #test_name; \
        new_test.group = #group_name; \
        new_test.fn = &__impl__##group_name##__##test_name##__; \
        __test_cache[__test_count] = new_test; \
        __test_count++; \
      } \
  int __impl__##group_name##__##test_name##__()
