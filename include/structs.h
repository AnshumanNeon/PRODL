#ifndef STRUCTS_H
#include <stddef.h>
#include <stdlib.h>

typedef struct INDIRECT_ADDRESS_TABLE_ENTRY {
  void* addr;
  unsigned int guard_counter;
  void* next_iat;
  void* prev_iat;
} IAT_entry;

typedef struct PTR {
  IAT_entry* iat;
  unsigned int counter;
} ptr;

#define STRUCTS_H
#endif
