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

void printList(struct Node* node) {
    struct Node* temp = node;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addNode(struct Node* node,int value) {
    struct Node* newNode = createNode(value);
    newNode->next = node;
    return newNode;
}


int main() {
    int n;

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
    printf("Moi ban nhap gia tri phan tu muon them ");
    scanf("%d",&n);
    head = addNode(head,n);
    printList(head);
    return 0;
}