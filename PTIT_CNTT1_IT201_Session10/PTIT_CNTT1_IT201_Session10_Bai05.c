#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

struct Node* deleteNodeWithValue(struct Node* head, int value) {

    while (head != NULL && head -> data == value) {
        struct Node* temp = head;
        head = head -> next;
        free(temp);
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current -> data == value) {
            prev -> next = current -> next;
            free(current);
            current = prev -> next;
        }else {
            prev = current;
            current = current -> next;
        }
    }
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
    current = current -> next;
    current -> next = createNode(5);

    printList(head);
    printf("Moi ban nhap so can xoa");
    scanf("%d",&n);
    head = deleteNodeWithValue(head, n);
    printList(head);
    free(head);
    return 0;

}