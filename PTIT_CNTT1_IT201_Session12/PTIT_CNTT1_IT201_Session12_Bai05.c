#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* deleteNodeValue(Node* head,int value) {
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }

    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            Node* temp = current;
            current->prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            current = current->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
}
int main() {
    int n;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(5);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);
    Node* node7 = createNode(5);
    Node* node8 = createNode(8);
    Node* node9 = createNode(5);
    Node* node10 = createNode(10);

    Node* head = node1;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    node6->next = node7;
    node7->prev = node6;
    node7->next = node8;
    node8->prev = node7;
    node8->next = node9;
    node9->prev = node8;
    node9->next = node10;
    node10->prev = node9;
    node10->next = NULL;
    printList(head);
    printf("Moi ban nhap vao phan tu muon xoa");
    scanf("%d",&n);
    head = deleteNodeValue(head,n);
    printList(head);
    return 0;
}