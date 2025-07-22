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

typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;

Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->arr = (Node **)malloc(sizeof(Node *)*capacity);
    newQueue->capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

void enqueue(Queue *queue, Node *node) {
    if (queue->rear == queue->capacity-1) {
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

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}

Node *delete(Node *root, int data){
    if (root == NULL) {
        return NULL;
    }
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    while (!isEmpty(queue)) {
        Node *node = dequeue(queue);
        if (node->data == data) {
            target = node;
        }
        if (node->left != NULL) {
            enqueue(queue, node->left);
            lastParent = node;
            lastNode = node->left;
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
            lastParent = node;
            lastNode = node->right;
        }
    }
    if (target == NULL) {
        free(queue->arr);
        free(queue);
        return root;
    }
    if (lastNode == NULL) {
        free(root);
        root = NULL;
    }else {
        target->data = lastNode->data;
        if (lastNode == lastParent->left) {
            lastParent->left = NULL;
        }else {
            lastParent->right = NULL;
        }
        free(lastNode);
    }
    free(queue->arr);
    free(queue);
    return root;
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    Node *root = NULL;
    root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);
    Node *node4 = createNode(6);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    inOrder(root);
    printf("\n");
    delete(root, 4);
    inOrder(root);
    return 0;
}