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
        printf("%d ", current->data);
        current = current -> next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    Node* current = head;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(5);
    printList(head);
    return 0;
}