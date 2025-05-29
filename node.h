#ifndef NODE_H
#define NODE_H

typedef struct node_t{
    void* data;
    struct node_t* next;
} node_t;

#endif