#include <stdio.h>

int n, cost[10][10], nears[10];

void readv();
void primsalg();
int findnextindex(int cost[10][10], int nears[10]);

void readv() {
    int i, j;
    printf("\nEnter the number of nodes or vertices: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Adjacency Matrix of the given graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if ((cost[i][j] == 0) && (i != j)) {
                cost[i][j] = 999;  // Representing infinity
            }
        }
    }
}

void primsalg() {
    int k, l, min = 999, a, t[10][10], u, i, j, mincost = 0;

    // Find the initial minimum edge
    for (i = 1; i <= n; i++) {
        for (u = 1; u <= n; u++) {
            if (i != u && cost[i][u] < min) {
                min = cost[i][u];
                k = i;
                l = u;
            }
        }
    }

    t[1][1] = k;
    t[1][2] = l;

    printf("\nThe Minimum Cost Spanning Tree is...");
    printf("\n(%d,%d) --> %d", k, l, min);

    for (i = 1; i <= n; i++) {
        if (i != k) {
            if (cost[i][l] < cost[i][k]) {
                nears[i] = l;
            } else {
                nears[i] = k;
            }
        }
    }

    nears[k] = nears[l] = 0;
    mincost = min;

    for (i = 2; i <= n - 1; i++) {
        j = findnextindex(cost, nears);
        t[i][1] = j;
        t[i][2] = nears[j];

        printf("\n(%d,%d) --> %d", t[i][1], t[i][2], cost[j][nears[j]]);
        mincost += cost[j][nears[j]];
        nears[j] = 0;

        for (k = 1; k <= n; k++) {
            if (nears[k] != 0 && cost[k][nears[k]] > cost[k][j]) {
                nears[k] = j;
            }
        }
    }

    printf("\nThe Required Minimum Cost of the Spanning Tree is: %d\n", mincost);
}

int findnextindex(int cost[10][10], int nears[10]) {
    int min = 999, a, k = -1, p;

    for (a = 1; a <= n; a++) {
        p = nears[a];
        if (p != 0) {
            if (cost[a][p] < min) {
                min = cost[a][p];
                k = a;
            }
        }
    }

    return k;
}

void main() {
    readv();
    primsalg();
}
