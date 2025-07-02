#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    struct Node* node= (struct Node*)malloc(sizeof(struct Node));
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

struct Node* deleteNode(struct Node* node) {
    struct Node* temp = node;
    node = node->next;
    return node;
}

int main() {
    int n;

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
    printf("Moi ban nhap vao gia tri can xoa ");
    scanf("%d",&n);
    head = deleteNode(head);
    printList(head);
    return 0;
}