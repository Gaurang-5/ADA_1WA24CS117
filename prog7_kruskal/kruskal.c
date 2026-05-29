/*
 * Program 7: Minimum Cost Spanning Tree – Kruskal's Algorithm
 * Find Minimum Cost Spanning Tree of a given undirected graph
 * using Kruskal's algorithm.
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>

int parent[10];

/* Find with path compression */
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

/* Union: returns 1 if union was performed, 0 if already in same set */
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[10][10];
    int i, j, min, mincost = 0;
    int a, b, u, v, ne = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    /* Initialise parent array */
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges selected:\n");

    while (ne < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d -> %d = %d\n", a, b, min);
            mincost += min;
            ne++;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}
