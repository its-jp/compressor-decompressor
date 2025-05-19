#pragma once

typedef struct priority_queue{
    huffman_node* head;
    huffman_node* tail;
    huffman_node* last;
    //I16 size; //Tamanho logico
} priority_queue;

priority_queue* priority_queue_create();
void priority_queue_enqueue(priority_queue* queue, &huffman_node huffman_node);
huffman_node* priority_queue_dequeue(priority_queue* queue);
void priority_queue_update(priority_queue* queue, huffman_node* huffman_node);
int node_exists(priority_queue* queue, huffman_node wanted_node); //retorna o indice do no se ele existe, senao ele retorna -1



