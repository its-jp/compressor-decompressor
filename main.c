#include <stdlib.h>
#include <stdio.h>
#include "meustiposonlinegdb.h"
#include "list.h"

int cmp_func(void* v1, void* v2);

int main(){

    FILE* file;

    char file_name[30];
    printf("Digite o nome do arquivo aqui: ");
    scanf("%s", file_name);
    printf("\n");

    file = fopen(file_name, "rb");
    if(file==NULL) return 0;

    U8* current_char = malloc(sizeof(U8));

    I16 frequency_table[256] = {0};

    while(fread(current_char, sizeof(char), 1, file)){
        frequency_table[*current_char]++;
    }

    free(current_char);

    list* l = init_list(cmp_func);

    for(int i = 0; i < 256; i++){
        if(frequency_table[i] > 0){
            printf("Caractere: %c, Frequencia: %d\n", (char)i, frequency_table[i]);
            add_element_list(l, &frequency_table[i]);
        }
    }

    /*fazer a parte de codificacao a partir daqui!*/
    return 0;
}


int cmp_func(void* v1, void* v2) {
    U8* a = (U8*)v1;
    U8* b = (U8*)v2;
    return *a - *b;
}