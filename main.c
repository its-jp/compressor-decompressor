#include <stdlib.h>
#include <stdio.h>
#include "meustiposonlinegdb.h"
#include "huffman_node.h"
#include "singly_linked_list_node.h"
#include "priority_queue.h"

void print_queue(priority_queue* queue){
    if(queue == NULL) return;
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
        frequency_table[*current_char]++;
    }

    //free(current_char);

    priority_queue* queue = priority_queue_create();

    for(I16 i = 0; i < sizeof(frequency_table)/sizeof(frequency_table[0]); i++){

        //Caso esse caractere nao exista no arquivo
        if(frequency_table[i] == 0) continue;

        U8 frequency_char = (char)i;
        I16 frequency_count = frequency_table[i];
        huffman_node* new_huffman_node = huffman_node_create(frequency_count, frequency_char);
        //printf("\n %c %i", new_huffman_node->character, new_huffman_node->frequency);

        //priority_queue_enqueue(queue, new_huffman_node);
        //print_queue(queue);
    }
    return 0;
}
