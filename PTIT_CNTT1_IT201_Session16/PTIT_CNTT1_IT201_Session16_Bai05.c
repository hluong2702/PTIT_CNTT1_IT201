#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *front;
    Node *rear;
}Queue;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return 1;
    }
    return 0;
}

void enqueue(Queue* queue, int data) {
    Node* node = createNode(data);
    if (isEmpty(queue)) {
        queue->front= queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

void display(Queue* queue) {
   if (isEmpty(queue)) {
       return;
   }
    Node* current= queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    Node* current = queue->front;
    queue->front = current->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(current);
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    deQueue(queue);
    display(queue);
    return 0;

}