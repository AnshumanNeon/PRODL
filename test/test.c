#include <stdio.h>
#include "memory.h"

int main() {
  int a = 4;
  alloc(16, &a);
  DEREF(&a, int) = 2;

  printf("%d\n", *((int*)get_addr(&a)));

  kill(&a);
  clean();

  return 0;
}
