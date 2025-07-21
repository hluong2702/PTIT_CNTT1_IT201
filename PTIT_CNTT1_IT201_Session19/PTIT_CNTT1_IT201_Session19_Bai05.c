#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findValue(Node *root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1;
    }
    return findValue(root->left, data);
    return findValue(root->right, data);
}

int main() {
    int n;
    Node *root = NULL;
    root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);


    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("Moi ban nhap vao so muon tim kiem: ");
    scanf("%d", &n);
    if (findValue(root, n) == 1) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}