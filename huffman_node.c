#include "huffman_node.h"
#include <stdlib.h>
huffman_node* huffman_node_create_empty(){
    huffman_node* node = (huffman_node*) malloc(sizeof(huffman_node));
    if(node==NULL) return NULL;

    node->frequency = 0;
    node->character = '\0';
    node->left = NULL;
    node->right = NULL;
}


huffman_node* huffman_node_create(I16 frequency, char character){
    huffman_node* node = (huffman_node*) malloc(sizeof(huffman_node));
    if(node==NULL) return NULL;

    node->frequency = frequency;
    node->character = character;
    node->left = NULL;
    node->right = NULL;

    return node;
}