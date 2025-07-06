#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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

Node* addNodePosition(Node* head, int value, int pos) {
    if (pos == 1) {
        Node* newNode = createNode(value);
        newNode->next = head;
       if (head != NULL) {
           head->prev = newNode;
       }
        head = newNode;
        return head;
    }
    Node* newNode = createNode(value);
    Node* current = head;
    int count = 1;
    while (current != NULL && count < pos -1) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

int main() {

    int n,pos;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

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

    printf("Moi ban nhap vao vi tri them phan tu");
    scanf("%d",&pos);
    printf("Moi ban nhap vao gia tri cua phan tu");
    scanf("%d",&n);
    head = addNodePosition(head,n,pos);
    printList(head);
    return 0;
}