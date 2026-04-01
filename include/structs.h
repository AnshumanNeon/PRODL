#ifndef STRUCTS_H
#include <stddef.h>
#include <stdlib.h>

typedef struct INDIRECT_ADDRESS_TABLE_ENTRY {
  unsigned int guard_counter;
  void* addr;
  struct INDIRECT_ADDRESS_TABLE_ENTRY* next_iat;
  struct INDIRECT_ADDRESS_TABLE_ENTRY* prev_iat;
} IAT_entry;

typedef struct PTR {
  IAT_entry* iat;
  unsigned int counter;
} ptr;

#define STRUCTS_H
#endif
