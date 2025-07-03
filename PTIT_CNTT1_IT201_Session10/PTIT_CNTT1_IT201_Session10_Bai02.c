#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("data: %d \n", current->data);
        current = current->next;
    }
}

int main() {
    struct Node* head = createNode(5);
    Node* current = head;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(1);

    printList(head);
    return 0;

}