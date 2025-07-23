#include <stdio.h>

void addEdge(int graph[4][4],int firstNode,int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

int main() {
    int graph[4][4]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    for (int i = 0; i <4;i++) {
        for (int j = 0; j <4;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
