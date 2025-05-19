#include <stdlib.h>
#include <stdio.h>
#include "./header-files/meustiposonlinegdb.h"
int main(){

    FILE* file;
    char file_name[30];
    printf("Digite o nome do arquivo aqui!:");
    scanf("%s", file_name);
    printf("\n");
    file = fopen(file_name, "rb");
    if(file == NULL) return 0;

    U8* current_char = (U8*) malloc(sizeof(U8));

    I16 frequency_table[256];
    while(fread(current_char, sizeof(U8), 1, file)){
        frequency_table[*current_char] += 1;
    }
    free(current_char);

    for(I16 i = 0; i < sizeof(frequency_table)/sizeof(frequency_table[0]); i++){

        //Caso esse caractere nao exista no arquivo
        if(frequency_table[i] == 0) continue;

        
    }

    return 0;
}
