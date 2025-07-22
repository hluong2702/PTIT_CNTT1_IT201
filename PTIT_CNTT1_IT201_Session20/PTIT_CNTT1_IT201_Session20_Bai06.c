#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findLevel(Node *root,int value,int level) {
    if(root==NULL) {
        return -1;
    }
    if(root->data==value) {
        return level;
    }
    int leftLevel = findLevel(root->left,value,level+1);
    if (leftLevel != -1) {
        return leftLevel;
    }
    int rightLevel = findLevel(root->right,value,level+1);
    return rightLevel;
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

    int value;
    printf("Moi ban nhap vao gia tri can tim ");
    scanf("%d",&value);
    int level = findLevel(root,value,0);
    if (level !=-1) {
        printf("%d",findLevel(root,value,0));
    }else{
        printf("Not found");
    }
    return 0;
}
