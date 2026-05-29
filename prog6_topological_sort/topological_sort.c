/*
 * Program 6: Topological Ordering of Vertices in a Digraph
 * Write a program to obtain the Topological ordering of
 * vertices in a given digraph.
 *
 * Method: Kahn's Algorithm (BFS / Indegree method)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>

#define MAX 100

void topoSort(int V[MAX][MAX], int n) {
    int indegree[MAX], visited[MAX], TP[MAX];
    int th_count = 0;

    /* Compute in-degrees */
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (V[j][i] == 1)
                indegree[i]++;
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    /* Kahn's BFS-based topological sort */
    while (1) {
        int w = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }

        if (w == -1) break;  /* No unvisited zero-indegree node */

        TP[th_count++] = w;
        visited[w] = 1;

        /* Reduce indegree of all neighbours of w */
        for (int i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                indegree[i]--;
            }
        }
    }

    if (th_count < n) {
        printf("No Topological sequence (cycle detected)\n");
    } else {
        printf("Topological sequence: ");
        for (int i = 0; i < th_count; i++)
            printf("%d ", TP[i]);
        printf("\n");
    }
}

int main() {
    int n;
    int V[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &V[i][j]);

    topoSort(V, n);
    return 0;
}
