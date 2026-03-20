#ifndef FIFO_H

#include "structs.h"

void insert(IAT_entry* iat);
IAT_entry* get_free_iat(void* addr);
void clean();

IAT_entry* head_iat;
IAT_entry* tail_iat;

#define FIFO_H
#endif
