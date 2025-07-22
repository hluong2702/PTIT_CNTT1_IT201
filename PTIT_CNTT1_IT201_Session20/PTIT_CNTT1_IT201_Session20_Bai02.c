#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node * createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}

void inOrderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrderDFS(root->left);
    printf("%d ", root->data);
    inOrderDFS(root->right);
}

void postOrderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrderDFS(root->left);
    postOrderDFS(root->right);
    printf("%d ", root->data);
}

typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;

Queue * createQueue(int capacity) {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->arr = (Node **)malloc(sizeof(Node *)*capacity);
    newQueue->capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

void enQueue(Queue *queue, Node *node) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}

int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}


void levelOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue *queue = createQueue(10);
    enQueue(queue, root);
    while (!isEmpty(queue)) {
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        if (node->left != NULL) {
            enQueue(queue, node->left);
        }
        if (node->right != NULL) {
            enQueue(queue, node->right);
        }
    }
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

    printf("Inorder traversal:\n");
    inOrderDFS(root);
    printf("\n");
    printf("Pre Order traversal:\n");
    preOrderDFS(root);
    printf("\n");
    printf("Post Order traversal:\n");
    postOrderDFS(root);
    printf("\n");
    printf("Level Order traversal:\n");
    levelOrder(root);
    printf("\n");
    return 0;
}