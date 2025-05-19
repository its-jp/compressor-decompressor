#pragma once

#include "huffman_node.h"
#include "priority_queue.h"

typedef struct huffman_tree{
    huffman_node* root;
} huffman_tree;


huffman_tree* huffman_tree_create(priority_queue* queue);