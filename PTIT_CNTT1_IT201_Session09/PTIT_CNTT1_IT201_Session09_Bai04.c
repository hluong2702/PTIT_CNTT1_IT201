#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    node -> next = NULL;
    return node;
}
int countNode(struct Node* node) {
    int count = 0;
    struct Node* current = node;
    while (current != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}

int main() {
    Node* head = createNode(1);
    Node* current = head;
    current -> next = createNode(2);
    current = current -> next;
    current -> next = createNode(3);
    current = current -> next;
    current -> next = createNode(4);
    current = current -> next;
    current -> next = createNode(5);

    int nodeCount = countNode(head);
    printf("Danh sach lien ket co %d phan tu ",nodeCount);
    return 0;

}