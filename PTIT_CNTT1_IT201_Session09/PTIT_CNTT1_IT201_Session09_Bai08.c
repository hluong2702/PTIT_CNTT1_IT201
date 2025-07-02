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
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
struct Node* deletePosition(struct Node* head, int position) {
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Khong hop le");
        return head;
    }
    prev->next = current->next;
    return head;
}

int main() {
    int pos;

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
    printf("Moi ban nhap vao vi tri muon xoa ");
    scanf("%d",&pos);
    head = deletePosition(head,pos);
    printList(head);
    return 0;
}