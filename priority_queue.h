#pragma once

#include "meustiposonlinegdb.h"
#include "singly_linked_list_node.h"

typedef struct priority_queue{
    struct singly_linked_list_node* head;
    struct singly_linked_list_node* last;
    I16 size; //Tamanho logico
} priority_queue;

priority_queue* priority_queue_create();
void priority_queue_enqueue(priority_queue* queue, huffman_node* huffman_node);
huffman_node* priority_queue_dequeue(priority_queue* queue);
void priority_queue_update(priority_queue* queue, huffman_node* huffman_node);
boolean node_exists(priority_queue* queue, huffman_node wanted_node);



