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

int deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    int value = queue->arr[queue->front];
    queue->front++;
    return value;
}

int seriesIncreasesSteadily(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    int prev = deQueue(queue);
    while (!isEmpty(queue)) {
        int current = deQueue(queue);
        if (current - prev != 1) {
            return 0;
        }
        prev = current;
    }
    return 1;
}

int main() {
    Queue* queue = createQueue(5);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    if (seriesIncreasesSteadily(queue)) {
        printf("True");
    }
    else {
        printf("False");
    }
    return 0;
}
