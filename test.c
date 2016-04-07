#include <sys/time.h>

#include "test.h"

static void __attribute__ ((constructor)) __init__tests__() {
  __test_count = 0;
}

static double current_time_in_ms() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return ((tv.tv_sec) * 1000.0) + ((tv.tv_usec) / 1000.0);
}

int main(void) {
  int i, failed_count;
  struct test_t failed_tests[10000];
  double start_time = current_time_in_ms();

  failed_count = 0;

  for(i = 0; i < __test_count; i++) {
    int result = __test_cache[i].fn();

    if(result) {
      printf("\033[1;32m.\033[0m");
    } else {
      printf("\033[1;31mF\033[0m");
      failed_tests[failed_count] = __test_cache[i];
      failed_count++;
    }
  }

  double duration = current_time_in_ms() - start_time;

  printf("\n\n");

  for(i = 0; i < failed_count; i++) {
    struct test_t failed = failed_tests[i];

    printf("%s %s failed.\n", failed.group, failed.name);
  }

  printf("\n");
  printf("Finished in %.3f seconds.\n", duration);

  return failed_count == 0 ? 0 : 1;
}
