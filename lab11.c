#include <stdio.h>

void bfs(int a[10][10], int n, int u) {
    int front, rear, q[10], visited[10], v, i;
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    front = 0;
    rear = -1;
    printf("\nThe nodes visited from %d are:\n", u);
    q[++rear] = u;
    visited[u] = 1;
    printf("%d\t", u);
    while (front <= rear) {
        u = q[front++];
        for (v = 1; v <= n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                printf("%d\t", v);
                visited[v] = 1;
                q[++rear] = v;
            }
        }
    }
}

void dfs(int a[10][10], int u, int visited[10], int n) {
    int v;
    visited[u] = 1;
    printf("%d\t", u);
    for (v = 1; v <= n; v++) {
        if (a[u][v] == 1 && visited[v] == 0)
            dfs(a, v, visited, n);
    }
}

void main() {
    int a[10][10], n, source, i, j, visited[10] = {0}, ch;
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the graph as adjacency matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter source vertex: ");
    scanf("%d", &source);
    do {
        printf("\n1. BFS method\n2. DFS Method\n3. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nBFS OF GIVEN GRAPH\n");
                bfs(a, n, source);
                break;
            case 2:
                printf("\nNodes visited from source using DFS Method are:");
                dfs(a, source, visited, n);
                break;
            case 3:
                break;
            default:
                printf("Enter a valid choice:");
        }
    } while (ch != 3);
}
