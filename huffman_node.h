#pragma once

#include "meustiposonlinegdb.h"
typedef struct huffman_node {
    U32 frequency;
    U8 character;
    struct huffman_node* left;
    struct huffman_node* right;
} huffman_node;


huffman_node* huffman_node_create_empty();
huffman_node* huffman_node_create(I16 frequency, char character);