#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
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

void insert_at_beginning(int value, Node** head) {
    Node* node = construct_node(value);
    node->next = *head;
    *head = node;
}

void insert_at_end(int value, Node* head) {
    Node* current = head;
    Node* node = construct_node(value);

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

void display_list(Node* head) {
    const char ANSI_RED[] = "\033[1;31m";
    const char ANSI_ORANGE[] = "\033[38;5;208m";
    const char ANSI_YELLOW[] = "\033[33m";
    const char ANSI_RESET[] = "\033[0m";
    
    printf("%sLinked List: %s", ANSI_RED, ANSI_RESET);
    Node* current = head;

    while(current != NULL) {
        printf("%s%d%s", ANSI_ORANGE, current->value, ANSI_RESET);
        
        if (current->next != NULL) {
            printf("%s -> %s", ANSI_YELLOW, ANSI_RESET);
        }
       
        current = current->next;
    }
        
    printf("\n");
}

void free_memory(Node* head) {
    Node* current = head;
    Node* next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = construct_node(1);
    insert_at_end(2, head);
    insert_at_end(3, head);
    insert_at_end(4, head);
    insert_at_end(5, head);
    display_list(head);
    free_memory(head);
    return 0;
}
