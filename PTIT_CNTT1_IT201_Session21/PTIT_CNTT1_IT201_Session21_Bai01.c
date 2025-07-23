#include <stdio.h>

void addEdge(int graph[3][3],int firstNode,int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

int main() {
    int graph[3][3]={
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    addEdge(graph,0,1);
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}