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
    newQueue->arr = (Node **)malloc(sizeof(Node *) * capacity);
    newQueue->capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

void enqueue(Queue *queue, Node *node) {
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

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}

Node *insert(Node *root, int data) {
    Node *newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
    }
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node *node = dequeue(queue);
        if (node->left == NULL) {
           node->left = newNode;
            break;
        }else {
            enqueue(queue, node->left);
        }
        if (node->right == NULL) {
           node->right = newNode;
            break;
        }else {
            enqueue(queue, node->right);
        }
    }
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
    int n;
    Node *root = NULL;
    root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    inOrder(root);
    printf("\n");
    insert(root, 9);

    inOrder(root);
    return 0;

}