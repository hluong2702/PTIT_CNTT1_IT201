#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(sizeof(int) * capacity);
    return queue;
}

void isEmpty(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("True");
        return;
    }
    printf("False");
    return;
}

void enQueue(Queue* queue, int value) {
    if (queue->rear < queue->capacity-1) {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}

int main() {
    Queue* queue = createQueue(5);
    enQueue(queue, 10);
    isEmpty(queue);
    return 0;
}