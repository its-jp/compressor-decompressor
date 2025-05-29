#include "list.h"
#include <stdlib.h>


list* init_list(int (*cmp)(void* v1, void* v2)){
    list* l = malloc(sizeof(list));
    l->head = NULL;
    l->cmp = cmp;
}


void add_element_list(list* l, void* data){
    if(l==NULL) return;

    if(l->head==NULL){
        l->head = malloc(sizeof(node_t));
        l->head->data = data;
        return;
    }

    node_t* current_node = l->head;
    node_t* antecessor = NULL;
    while(current_node!=NULL){

        antecessor = current_node;
        current_node = current_node->next;
    }
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    antecessor->next = new_node;
}