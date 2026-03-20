#include "memory.h"

int valid_ptr(ptr* p) {
  if(!p) return 0;
  if(!p->iat) return 0;
  if(!p->iat->addr) return 0;
  if(p->counter != p->iat->guard_counter) return 0;
  return 1;
}

int get_ptr(void* addr, void* p) {
  // find a free iat entry
  IAT_entry* iat = get_free_iat(addr);

  // get pointer
  *((ptr*)p) = (ptr){ .iat = iat, .counter = iat->guard_counter };

  return 1;
}

void* get_addr(void* p) {
  if(valid_ptr((ptr*)p)) {
    return ((ptr*)p)->iat->addr;
  }
  return 0;
}

int alloc(unsigned int size, void* p) {
  if (get_ptr(malloc(size), p)) return 1;

  return 0;
}

int kill(void* p) {
  if(!valid_ptr((ptr*)p)) return 0;

  // increase guard_counter
  ((ptr*)p)->iat->guard_counter++;
  
  // put iat into free list
  insert(((ptr*)p)->iat);

  // safety check
  ((ptr*)p)->iat = NULL;

  return 1;
}
