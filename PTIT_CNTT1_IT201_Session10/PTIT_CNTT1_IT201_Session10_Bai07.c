#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void printList(Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

struct Node* selectionSort(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* min = current;
        Node* temp = current -> next;

        while (temp != NULL) {
            if (temp -> data < min -> data) {
                min = temp;
            }
            temp = temp -> next;
        }
        if ( min != current) {
            int tempBox = current -> data;
            current -> data = min -> data;
            min -> data = tempBox;
        }
        current = current -> next;
    }
    return head;

}

int main() {
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
    head = selectionSort(head);
    printList(head);
    free(head);
    return 0;
}