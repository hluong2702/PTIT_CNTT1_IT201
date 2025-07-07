#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* addNodeEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* current = head;
    while (current ->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return newNode;
}

int main() {
    int n;
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);

    Node* head = node1;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = NULL;
    printList(head);
    printf("Moi ban nhap gia tri muon them");
    scanf("%d",&n);
    addNodeEnd(head, n);
    printList(head);
    return 0;
}