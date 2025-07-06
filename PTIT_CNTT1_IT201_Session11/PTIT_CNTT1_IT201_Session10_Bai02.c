#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void printList(struct Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Node %d : %d \n",count, current -> data);
        count ++;
        current = current -> next;
    }
}

int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    Node* head = node1;
    node1 -> next = node2;
    node2 -> prev = node1;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;

    printList(head);
    return 0;

}