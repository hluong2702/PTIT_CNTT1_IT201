#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int firstNode, int secondNode) {
    if (firstNode == secondNode) return;
    for (int i = 3; i >= 0; i--) {
            Node* newNode = createNode(secondNode);
            newNode->next = graph[firstNode];
            graph[firstNode] = newNode;
            return;
    }
}

void printGraph(Node *graph[],int size) {
    for (int i = 0; i < size; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* graph[3] = {NULL,NULL,NULL};
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 1);
    printf("Input 1: \n");
    printGraph(graph,3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 0);
    printf("\nInput 2: \n");
    printGraph(graph,3);
    return 0;
}