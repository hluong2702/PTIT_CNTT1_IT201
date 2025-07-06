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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* searchNode(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current -> data == value) {
            return current;
        }
        current = current -> next;
    }
    return NULL;
}

int main() {
    int n;

    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    Node* head = node1;
    head -> next = node2;
    node2 -> prev = head;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;
    node5 -> next = NULL;

    printList(head);
    printf("Moi ban nhap vao gia tri can tim ");
    scanf("%d",&n);

    Node* temp = searchNode(head,n);
    if (temp !=NULL) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}