/*
 * Program 9: Single Source Shortest Paths – Dijkstra's Algorithm
 * From a given vertex in a weighted connected graph, find shortest
 * paths to other vertices using Dijkstra's algorithm.
 *
 * ADA Lab - BMS College of Engineering
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

/* Find the vertex with minimum distance not yet visited */
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min       = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

/* Print shortest distances from source */
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int  dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i]    = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    /* Example weighted adjacency matrix */
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 9, 2},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 9, 9, 0, 10},
        {0, 0, 2, 14, 10, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
