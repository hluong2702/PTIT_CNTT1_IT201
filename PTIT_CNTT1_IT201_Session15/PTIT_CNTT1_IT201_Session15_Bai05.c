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
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

void enQueue(Queue* queue, int value) {
    if (queue->rear < queue->capacity - 1) {
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
        printf("Queue is empty\n");
    }
}

int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    return queue->arr[queue->front];
}


int main() {
    Queue* queue = createQueue(5);
    displayQueue(queue);
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    displayQueue(queue);
    printf("\nreturn value = %d\n", getFront(queue));
    return 0;
}