#pragma once

typedef struct huffman_node {
    U32 frequency;
    U8 character;
    huffman_node* left;
    huffman_node* right;
} huffman_node;


huffman_node* huffman_node_create_empty();
huffman_node* huffman_node_create(char character);