#include "memory.h"

int valid_ptr(ptr* p) {
  if(p->counter != p->iat->guard_counter) return false;
  if(p == NULL || p->iat == NULL || p->iat->addr == NULL) return false;
  return true;
}

ptr* get_ptr(unsigned int size) {
  // find a free iat entry
  IAT_entry* iat = get_free_iat();

  // get pointer
  ptr pointer = { .iat = iat, .counter = iat->counter };
  return &pointer;
}

void* get_addr(ptr* p) {
  if(valid_ptr(p)) {
    return p->iat->addr;
  }
  return false;
}

int kill(ptr* p) {
  if(!valid_ptr(p)) return false;

  // increase guard_counter
  p->iat->guard_counter++;
  
  // put iat into free list
  insert(p->iat);

  // safety check
  p->iat = NULL;

  return true;
}
