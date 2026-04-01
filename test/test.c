#include <stdio.h>
#include "memory.h"

int main() {
  char a = '1';
  alloc(4, &a);
  DEREF(&a, char) = 'a';

  printf("%c\n", DEREF(&a, char));

  kill(&a);
  clean();

  return 0;
}
