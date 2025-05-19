#pragma once
#include "meustiposonlinegdb.h"


typedef struct huffman_code {
    U8* byte /* vetor dinâmico de bytes */; 
    U8 capacity /*capacidade em bits */;
    U8 size /*tamanho em bits */;
} huffman_code;

boolean init_code (huffman_code* c /* por referência */);
void free_code (huffman_code* c /* por referência */);

boolean add_bit (huffman_code* c /* por referência */,
                      U8 value /* 0 ou 1 */);
boolean throw_bit (huffman_code* c /* por referência */);

boolean clone (huffman_code original, /* por valor */
               huffman_code* copy /* por referencia */);