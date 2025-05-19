#include <stdlib.h>
#include <stdio.h>
#include "meustiposonlinegdb.h"
#include "huffman_node.h"
#include "singly_linked_list_node.h"
#include "priority_queue.h"

void print_queue(priority_queue* queue){
    singly_linked_list_node* node = queue->head;
    while(node != NULL){
        
        printf("Character: %c Amount:%i \n", node->data.character, node->data.frequency);
        node = node->next;
    }
}
int main(){

    FILE* file;
    char file_name[30];
    printf("Digite o nome do arquivo aqui!:");
    scanf("%s", file_name);
    printf("\n");
    file = fopen(file_name, "rb");
    if(file == NULL) return 0;

    U8* current_char = (U8*) malloc(sizeof(U8));

    I16 frequency_table[256] = {0};
    while(fread(current_char, sizeof(U8), 1, file)){
        frequency_table[*current_char] += 1;
    }
    free(current_char);

    priority_queue* queue = priority_queue_create();

    for(I16 i = 0; i < sizeof(frequency_table)/sizeof(frequency_table[0]); i++){

        //Caso esse caractere nao exista no arquivo
        if(frequency_table[i] == 0) continue;

        U8 frequency_char = (char)i;
        I16 frequency_count = frequency_table[i];
        huffman_node* new_huffman_node = huffman_node_create(frequency_count, frequency_char);

        priority_queue_enqueue(queue, new_huffman_node);
        
        
    }

    //O problema esta no dequeue
    huffman_node* huff_node = priority_queue_dequeue(queue);
    print_queue(queue);
    printf("%c %i", huff_node->character, huff_node->frequency);
    return 0;
}
