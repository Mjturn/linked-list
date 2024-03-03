#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct Node* next;
} Node;

Node* construct_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
   
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    node->value = value;
    node->next = NULL;
   
    return node;
}

int main() {
    Node* node = construct_node(5);
    printf("Node Value: %d\n", node->value);
    free(node);
    return 0;
}
