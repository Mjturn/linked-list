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

Node* insert_at_beginning(int value, Node** head) {
    Node* node = construct_node(value);
    node->next = *head;
    *head = node;
    return node;
}

Node* insert_at_end(int value, Node* head) {
    Node* current = head;
    Node* node = construct_node(value);

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = node;
    return node;
}

void remove_from_beginning(Node** head) {
    if(*head == NULL) {
        return;
    }
    
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void remove_from_end(Node** head) {
    Node* current = *head;

    if(*head == NULL) {
        return;
    }

    if((*head)->next == NULL) {
        *head = NULL;
        free(*head);
        return;
    }

    while(current->next->next != NULL) {
        current = current->next;
    }

    current->next = NULL;
    free(current->next);
}

void display_list(Node* head) {
    printf("Linked List: ");
    Node* current = head;

    while(current != NULL) {
        printf("%d", current->value);
        
        if (current->next != NULL) {
            printf(" -> ");
        }
       
        current = current->next;
    }
        
    printf("\n");
}

int get_length(Node* head) {
    Node* current = head;
    int length = 0;

    while(current != NULL) {
        length++;
        current = current->next;
    }

    return length;
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
    Node* node_1 = construct_node(1);
    Node* node_2 = insert_at_end(2, node_1);
    Node* node_3 = insert_at_end(3, node_1);
    Node* node_4 = insert_at_end(4, node_1);
    Node* node_5 = insert_at_end(5, node_1);
    display_list(node_1);
    printf("Length: %d\n", get_length(node_1));
    free_memory(node_1);
    return 0;
}
