#ifndef STRUCTS_H

typedef struct INDIRECT_ADDRESS_TABLE_ENTRY {
  void* addr;
  unsigned int guard_counter;
  IAT_entry* next_iat;
  IAT_entry* prev_iat;
} IAT_entry;

typedef struct PTR {
  IAT_entry* iat;
  unsigned int counter;
} ptr;

#define STRUCTS_H
#endif
