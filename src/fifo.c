#include "fifo.h"

void insert(IAT_entry* iat) {
  iat->addr = NULL;
  iat->prev_iat = NULL;
  iat->next_iat = NULL;

  if(tail_iat != NULL) {
    tail_iat->next_iat = iat;
    iat->prev_iat = tail_iat;
  }
  tail_iat = iat;
}

IAT_entry* get_free_iat(void* addr) {
  if(head_iat == NULL) {
    tail_iat = NULL;
    IAT_entry* iat = (IAT_entry*)malloc(sizeof(IAT_entry));
    iat->guard_counter = 0;
    insert(iat);
    head_iat = tail_iat;
    head_iat->next_iat = NULL;
  }
  
  IAT_entry* tmp = head_iat;

  if(head_iat == tail_iat) {
    head_iat = NULL;
    tail_iat = NULL;
  }
  else {
    head_iat = head_iat->prev_iat;
    head_iat->next_iat = NULL;
  }

  tmp->addr = addr;
  
  return tmp;
}

// make sure all iat entries (free or not) are pushed back into the free list so that they can be freed
void clean() {
  while(tail_iat != NULL) {
    IAT_entry* tmp = tail_iat;
    tail_iat = tail_iat->next_iat;
    free(tmp);
  }
}
