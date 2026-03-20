#ifndef FIFO_H

#include "structs.h"

typedef struct IAT_NODE {
  IAT_entry entry;
  node* next_node;
} node;

node* head_node;
node* tail_node;

#define FIFO_H
#endif
