#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define INF 999999

int n;  // number of nodes
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int visited[MAX_NODES];
int parent[MAX_NODES];

int minDistance() {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent[j]);
    printf("%d ", j);
}

void printSolution() {
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < n; i++) {
        printf("\n%d -> %d \t\t %d\t\t", 0, i, dist[i]);
        printPath(i);
    }
}

void dijkstra(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution();
}

int main() {
    int edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph with INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // Input edge information
    printf("Enter edge information (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;  // For undirected graph
    }

    dijkstra(0);  // Assuming source vertex is 0

    return 0;
}
