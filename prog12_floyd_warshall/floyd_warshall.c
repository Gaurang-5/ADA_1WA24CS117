/*
 * Program 12: All Pair Shortest Paths – Floyd's Algorithm
 * Implement All Pair Shortest paths problem using Floyd's
 * (Floyd-Warshall) algorithm.
 *
 * Time Complexity: O(V^3)
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>

#define INF 1e6

void floydWarshall(int V, int dist[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1) return 0;

    int graph[V][V];
    printf("Enter matrix (-1 for INF):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int val;
            scanf("%d", &val);
            graph[i][j] = (i == j) ? 0 : (val == -1 ? (int)INF : val);
        }
    }

    floydWarshall(V, graph);
    return 0;
}
