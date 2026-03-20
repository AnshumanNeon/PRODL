#ifndef MEMORY_H

#include "structs.h"

int member(IAT_entry* iat, unsigned int counter, void* addr);

int alloc(unsigned int size);
int kill(ptr* p);

#define MEMORY_H
#endif
