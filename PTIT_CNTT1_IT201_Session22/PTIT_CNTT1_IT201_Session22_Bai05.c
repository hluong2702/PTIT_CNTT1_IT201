#include <stdio.h>

void addEdge(int graph[100][100],int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int adjacentPeak(int graph[100][100],int n,int k) {
    int count = 0;
    for(int i=0;i<n;i++) {
        if (graph[k][i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int graph[100][100];
    int n,v;
    printf("Moi ban nhap vao so dinh");
    scanf("%d",&n);
    printf("Moi ban nhap vao so canh");
    scanf("%d",&v);
    printf("Nhap cac canh ");
    for(int i=0;i<v;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        addEdge(graph,u,v);
    }
    int k;
    printf("Moi ban nhap vao k can kiem tra ");
    scanf("%d",&k);
    printf("So dinh ke voi %d la %d ",k,adjacentPeak(graph,n,k));
    return 0;

}