#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* searchNodeMiddle(Node* head) {
    Node* current = head;
    Node* temp = head;
    int count = 1;
    while (temp != NULL && temp->next != NULL) {
        current = current->next;
        temp = temp->next->next;
        count++;
    }
    printf("Node %d : %d ",count, current->data);
    return current;

}

int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);

    Node* head = node1;
    node1-> next = node2;
    node2-> prev = node1;
    node2->next = node3;
    node3->prev= node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    node6->next = NULL;
    printList(head);
    Node* mid = searchNodeMiddle(head);
    return 0;
}