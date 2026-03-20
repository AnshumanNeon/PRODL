#include <stdio.h>
#include "memory.h"

int main() {
  int* a = (int*)malloc(16);
  *a = 4;
  
  get_ptr(a, a);

  printf("%d\n", *((int*)get_addr(a)));

  kill(a);
  clean();

  return 0;
}
