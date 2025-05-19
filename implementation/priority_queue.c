#include "priority_queue.h"
#include "huffman_node.h"
#include <stdlib.h>
#include "singly_linked_list_node.h"
#include "meustiposonlinegdb.h"

#define TOTAL_ASCII_CODES 256

priority_queue* priority_queue_create(){
    priority_queue* queue = (priority_queue*) malloc(sizeof(priority_queue));
    if(queue == NULL) return;

    queue->head = (huffman_node*) malloc(sizeof(huffman_node));
    if(queue->head == NULL) return;
    queue->size = 0;
    return queue;
}
void priority_queue_enqueue(priority_queue* queue, huffman_node* huffman_node){

    if()
    singly_linked_list_node node;
    node.data = *huffman_node;

    if(*(queue->head) == NULL){
        queue->head = &node;
        queue->tail = &node;
        queue->size++;

        return;
    } 




    //fazer busca binaria para saber onde ele deve ser colocado, assim fazendo um swap com o 
}
huffman_node* priority_queue_dequeue(priority_queue* queue){

}
void priority_queue_update(priority_queue* queue, huffman_node* huffman_node){
    
}
boolean node_exists(priority_queue* queue, huffman_node wanted_node){ //retorna o indice do no se ele existe,senao retorna -1
    singly_linked_list_node* current_node = queue->head;
    queue->last_node = NULL;
    while(current_node!=NULL){
        U8 current_char = current_node->data.character;
        if(current_char == huffman_node.character) return 1;


        //Caso ja tenha passado por onde deveria estar: 
        //Isso eh bom pois para de procurar pelo no e tambem indica onde esse no poderia ser colocado (last.next)!
        if(current_node->data.frequency > wanted_node.frequency){
            break;
        }

        last_node = current_node;
        current_node = current_node->next;
    }
    return 0;
}