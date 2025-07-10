#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int cap;
}Queue;

Queue* createQueue(int cap) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->cap = cap;
    queue->rear = -1;
    queue->front = 0;
    queue->arr = (int*)malloc(sizeof(int) * cap);
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

void enQueue(Queue* queue, int value) {
    if (queue->rear < queue->cap - 1) {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }
}

void displayQueue(Queue* queue) {
    if (!isEmpty(queue)) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
    }else {
        printf("queue is empty \n");
    }
}

int main() {
    Queue* queue = createQueue(5);
    displayQueue(queue);
    enQueue(queue, 10);
    enQueue(queue, 20);
    displayQueue(queue);
    return 0;
}