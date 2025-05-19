#include "priority_queue.h"
#include "huffman_node.h"
#include <stdlib.h>
#include "meustiposonlinegdb.h"

#define TOTAL_ASCII_CODES 256

priority_queue* priority_queue_create(){
    priority_queue* queue = (priority_queue*) malloc(sizeof(priority_queue));
    if(queue == NULL) return NULL;

    queue->head = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
    if(queue->head == NULL) return NULL;
    queue->size = 0;
    return queue;
}
void priority_queue_enqueue(priority_queue* queue, huffman_node* huffman_node){
    if(node_exists(queue, *huffman_node)) return;

    //Caso seja o primeiro no
    if(queue->last == NULL){
        queue->head->data = *huffman_node;
        queue->head->next = NULL;
        queue->size++;
        return;
    }

    singly_linked_list_node* new_node = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
    if(new_node == NULL) return;
    new_node->data = *huffman_node;
    new_node->next = queue->last->next;
    queue->last->next = new_node;
    queue->size++;

}
huffman_node* priority_queue_dequeue(priority_queue* queue){
    if(queue->size == 0) return NULL;


    huffman_node* dequeued_node = (huffman_node*) malloc(sizeof(huffman_node));
    dequeued_node = &(queue->head->data);
    queue->head = queue->head->next;
    free(queue->head);
    queue->size--;
    return dequeued_node;
}
void priority_queue_update(priority_queue* queue, huffman_node* huffman_node){
    
}
boolean node_exists(priority_queue* queue, huffman_node wanted_node){ //retorna o indice do no se ele existe,senao retorna -1
    singly_linked_list_node* current_node = queue->head;
    queue->last = NULL;
    while(current_node!=NULL){
        U8 current_char = current_node->data.character;
        if(current_char == wanted_node.character) return 1;


        //Caso ja tenha passado por onde deveria estar: 
        //Isso eh bom pois para de procurar pelo no e tambem indica onde esse no poderia ser colocado (last.next)!
        if(current_node->data.frequency > wanted_node.frequency){
            break;
        }

        queue->last = current_node;
        current_node = current_node->next;
    }
    return 0;
}