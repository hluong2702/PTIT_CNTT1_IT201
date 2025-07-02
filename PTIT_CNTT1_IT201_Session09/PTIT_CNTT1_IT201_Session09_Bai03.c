#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}

struct Node* searchNode(struct Node* head , int value) {
    struct Node* current = head;
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

    Node* head = createNode(1);
    Node* current = head;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(5);

    printf("Moi ban nhap vao gia tri can tim ");
    scanf("%d",&n);
    struct Node* temp = searchNode(head,n);
    if (temp !=NULL) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}