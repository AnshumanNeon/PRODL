#include <stdio.h>
#include "memory.h"

int main() {
  int* a = (int*)malloc(4);
  *a = 4;
  
  get_ptr(a, a);

  printf("%d\n", *((int*)get_addr(a)));

  return 0;
}
