#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void printList(Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

struct Node* middleNode(struct Node* head) {
    struct Node* temp = head;
    struct Node* prev = head;
    int count = 1;
    while (prev != NULL && prev -> next != NULL) {
        temp = temp -> next;
        prev = prev -> next -> next;
        count++;
    }
    printf("Node %d: %d ",count, temp -> data);
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
    current = current -> next;
    current -> next = createNode(6);

    printList(head);
    Node* mid = middleNode(head);
    free(head);
    return 0;

}