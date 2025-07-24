#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **adjMatrix;
}Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}

void addEgde(Graph *graph,int u, int v) {
   graph->adjMatrix[u][v]=graph->adjMatrix[v][u]=1;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ",i);
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
    addEgde(graph,0,1);
    addEgde(graph,0,2);
    addEgde(graph,1,2);
    addEgde(graph,3,2);
    addEgde(graph,1,3);
    addEgde(graph,3,4);
    printGraph(graph);
    return 0;

}