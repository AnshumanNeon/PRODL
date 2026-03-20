#ifndef MEMORY_H

#include "structs.h"
#include "fifo.h"

int valid_ptr(ptr* p);

int get_ptr(void* addr, void* p);
void* get_addr(void* p);
int kill(void* p);

#define MEMORY_H
#endif
