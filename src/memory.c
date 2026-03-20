#include "memory.h"

int member(IAT_entry* iat, unsigned int counter, void* addr) {
  if(counter != iat->guard_counter) return false;

  addr = iat->addr;
  return true;
}

int alloc(unsigned int size) {
  // find a free iat entry

  // allocate and shit
}

int kill(ptr* p) {
  if(p == NULL) return false;

  if(p->counter != p->iat.guard_counter) return false;

  p->iat.guard_counter++;

  // put iat into free list

  // last used procedures
}
