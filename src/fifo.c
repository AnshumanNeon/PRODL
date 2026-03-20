#include "fifo.h"

void insert(IAT_entry* iat) {
  node* temp_node;
  
  if(iat == NULL) {
    temp_node = (node*)malloc(sizeof(node));
    temp_node->next_node = NULL;
  }
  else {
    temp_node = iat;
  }

  if(rear_node == NULL) {
    head_node = temp_node;
    rear_node = temp_node;
  }
  else {
    node* tmp = rear_node;
    rear_node = temp_node;
    rear_node->next_node = tmp;
  }
}

IAT_entry* get_free_iat() {
  if(head_node == NULL) {
    rear_node = front_node;
    return;
  }
  else {
    node* temp_node = head_node;
    head_node = head_node->next_node;
    return &temp_node->entry;
  }
}

void clean() {
  while(rear_node != NULL) {
    node* tmp = rear_node;
    rear_node = rear_node->next_node;
    free(tmp);
  }
}
