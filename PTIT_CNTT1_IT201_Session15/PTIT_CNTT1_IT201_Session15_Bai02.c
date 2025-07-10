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

int isFull(Queue* queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}

void enQueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->rear < queue->capacity - 1) {
        queue->rear++;
        queue->arr[queue->rear] = value;
    }

}

int isEmpty(Queue* queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

void displayQueue(Queue* queue) {
    if (!isEmpty(queue)) {
        for (int i = queue->front; i <= queue->rear ; i++) {
            printf("%d ", queue->arr[i]);
        }
    }
}


int main() {
    Queue* queue = createQueue(5);
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    enQueue(queue, 50);
    int n;
    printf("Moi ban nhap vao so muon them vao mang");
    scanf("%d", &n);
    enQueue(queue, n);
    displayQueue(queue);
    return 0;
}