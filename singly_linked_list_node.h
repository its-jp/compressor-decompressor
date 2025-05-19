#pragma once

#include "huffman_node.h"

typedef struct singly_linked_list_node {
    huffman_node data;
    struct singly_linked_list_node* next;
} singly_linked_list_node;