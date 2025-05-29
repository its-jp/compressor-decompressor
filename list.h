#ifndef LIST_H
#define LIST_H

#include "node.h"
typedef struct list{
    node_t* head;
    int (*cmp) (void* v1, void* v2);
} list;

list* init_list(int (*cmp)(void* v1, void* v2));
void add_element_list(list* l, void* data);
node_t* remove_element_list(list* l, void* data);
void update_element(list* l, void* old_data, void* new_data);

#endif