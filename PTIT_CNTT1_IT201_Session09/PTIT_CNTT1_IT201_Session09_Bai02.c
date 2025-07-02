#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}

void prirntList(Node* head) {
    struct Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf(" Node %d: %d ",count, current -> data);
        count ++;
        current = current -> next;
    }
    printf("\n");
}


int main() {
    Node* head = createNode(1);
    Node* current = head;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(5);

    prirntList(head);
    return 0;

}