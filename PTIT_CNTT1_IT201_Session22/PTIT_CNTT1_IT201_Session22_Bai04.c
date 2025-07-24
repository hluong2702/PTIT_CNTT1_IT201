#include <stdio.h>

int countEdges(int graph[100][100],int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int graph[100][100];
    int n;
    printf("Moi ban nhap vao dinh ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("%d\n",countEdges(graph,n));
    return 0;

}