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

int findMax(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);
    if (maxLeft > maxRight) {
        return maxLeft;
    }else if (maxLeft < maxRight) {
        return maxRight;
    }
    return root->data;
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
    printf("%d\n", findMax(root));
    return 0;

}