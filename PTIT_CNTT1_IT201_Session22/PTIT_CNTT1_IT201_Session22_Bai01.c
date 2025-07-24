#include <stdio.h>

void addEdge(int graph[100][100],int u,int v ) {
    graph[u][v] = graph[v][u] = 1;
}

int main() {
    int graph[100][100];
    int n;
    printf("Moi ban nhap vao so dinh : ");
    scanf("%d",&n);
    printf("\n");
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,3,2);
    addEdge(graph,1,3);
    addEdge(graph,3,4);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}