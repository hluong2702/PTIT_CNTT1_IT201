#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countLeaves(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node *root = NULL;
    root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    printf("%d\n", countLeaves(root));
    return 0;

}