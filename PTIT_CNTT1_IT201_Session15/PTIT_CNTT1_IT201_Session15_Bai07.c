#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    char arr[100][31];
    int front;
    int rear;
    int capacity;
}Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int isFull(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;

}

int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

void enQueue(Queue *queue, char *name) {
    strcpy(queue->arr[++queue->rear], name);

}

void deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return;
    }
    printf("%s\n", queue->arr[queue->rear]);
}

void displayQueue(Queue* queue) {
    if (!isEmpty(queue)) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%s", queue->arr[i]);
        }
    }
}

int main() {
    Queue *queue = createQueue(100);
    int choice;
    char name[31];

    do {
        printf("\n Quay ban ve \n");
        printf("1.Them khach hang\n");
        printf("2.Phuc vu khach hang\n");
        printf("3.Hien thi danh sach khach dang cho\n");
        printf("4.Thoat chuong trinh\n");
        printf("Moi ban nhap lua chon\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Moi ban nhap ten khach hang");
                fgets(name, 31, stdin);
                name[strlen(name) - 1] = '\0';
                enQueue(queue, name);
                break;
            case 2:
                deQueue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Thank you");
                return 0;
            default:
                printf("Lua chon khong hop le vui long chon lai");
                break;
        }
    }while (choice != 4);
    return 0;
}