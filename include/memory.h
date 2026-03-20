#ifndef MEMORY_H

#include "structs.h"
#include "fifo.h"

int valid_ptr(ptr* p);

int get_ptr(void* addr, void* p);
void* get_addr(void* p);

int alloc(unsigned int size, void* p);
int kill(void* p);

// derefernece a given pointer of a given type
#define DEREF(p, type) *((type*)get_addr(p))

#define MEMORY_H
#endif
