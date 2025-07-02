#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addNodePosition(struct Node* head, int value , int position) {
    if (position == 1) {
        struct Node* newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    if (count < position) {
        printf("Khong hop le");
        return head;
    }
    prev->next = newNode;
    newNode->next = current;
    return head;
}

int main() {

    int n, pos;
    Node* head = createNode(1);
    Node* current = head;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(5);

    printList(head);
    printf("Moi ban nhap vao gia tri can them ");
    scanf("%d",&n);
    printf("Moi ban nhap vao vi tri muon them ");
    scanf("%d",&pos);
    head = addNodePosition(head,n,pos);
    printList(head);
    return 0;

}