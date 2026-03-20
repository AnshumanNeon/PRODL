#include <stdio.h>
#include "memory.h"

int main() {
  void* a = malloc(16);
  *(int*)a = 4;
  
  get_ptr(a, a);

  printf("%d\n", *((int*)get_addr(a)));

  kill(a);
  clean();

  return 0;
}
