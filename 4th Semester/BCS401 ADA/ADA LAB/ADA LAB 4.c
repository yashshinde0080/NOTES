#include <stdio.h>

void readf();
void SP();

int cost[20][20], dist[20], s[20];
int n, u, min, v, w;

void readf() {
    int i, j;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Adjacency Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // Representing no edge
        }
    }
}

void SP() {
    int i, j;

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialization
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }

    s[v] = 1;
    dist[v] = 0;

    // Main loop of Dijkstra's algorithm
    for (i = 2; i <= n; i++) {
        min = 999;

        // Find the unvisited node with minimum distance
        for (j = 1; j <= n; j++) {
            if (s[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        s[u] = 1;

        // Update distances
        for (w = 1; w <= n; w++) {
            if (s[w] == 0 && cost[u][w] != 999) {
                if (dist[w] > dist[u] + cost[u][w]) {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }

    // Print shortest distances
    printf("\nFrom the Source Vertex %d:", v);
    for (i = 1; i <= n; i++) {
        printf("\n%d -> %d = %d", v, i, dist[i]);
    }
}

void main() {
    readf();
    SP();
}
