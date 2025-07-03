#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* addNodeEnd(struct Node* head , int value ) {
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    while (current ->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
int main() {
    int n;
    struct Node* head = createNode(5);
    Node* current = head;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(1);

    printList(head);
    printf("Moi ban nhap vao gia tri nguyen");
    scanf("%d",&n);

    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }
    head = addNodeEnd(head, n);
    printList(head);
    return 0;
}