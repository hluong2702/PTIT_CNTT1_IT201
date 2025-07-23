#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **adjMatrix;
}Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    //cap phat bo nho cho mang 2 chieu
    graph->adjMatrix = (int **) malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++) {
        //cap nhat bo nho cho tung mang con ben trong mang 2 chieu
        graph->adjMatrix[i] = (int *)calloc(V,sizeof(int));
    }
    return graph;
}

//xay dung ham thiet lap canh
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// xay dung ham in do thi
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
// in kieu 1
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0

// in kieu 2
//0: 1 2
//1:
//2:
//3:


int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    printGraph(graph);
    return 0;

}