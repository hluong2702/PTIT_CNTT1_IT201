#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

typedef struct AdjList {
    Node *head;
}AdjList;

typedef struct Graph {
    int V;
    int **adjMatrix;
}Graph;

Node *createNode(int v) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

AdjList *ToAdjList(Graph *graph) {
    AdjList *list = (AdjList *)malloc(graph->V * sizeof(AdjList));
    for (int i = 0; i < graph->V; i++) {
        list[i].head = NULL;
    }
    for (int i = 0; i < graph->V; i++) {
        Node *prev = NULL;
        for (int j = 0; j < graph->V; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                Node *newNode = createNode(j);
                if (list[i].head == NULL) {
                    list[i].head = newNode;
                }else {
                    prev->next = newNode;
                }
                prev = newNode;
            }
        }
    }
    return list;
}

void printfAdjList(AdjList* list,int V) {
    for (int i = 0; i < V; i++) {
        printf("%d",i);
        Node *current = list[i].head;
        while (current != NULL) {
            printf(" %d",current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*) calloc(V,sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d ",i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Moi ban nhap vao so dinh ");
    scanf("%d",&n);
    Graph *graph = createGraph(n);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,3,2);
    addEdge(graph,1,3);
    addEdge(graph,3,4);
    printf("Ma tran ke\n");
    printGraph(graph);
    printf("\n");
    printf("Danh sach ke\n");
    AdjList *list = ToAdjList(graph);
    printfAdjList(list,graph->V);
    printf("\n");
    return 0;

}