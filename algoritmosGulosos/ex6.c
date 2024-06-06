#include <stdio.h>
#define INF 99999999
#define V 4

void printPath(int path[][V+1]) {
    printf("Circuito Euleriano :\n");
    for (int u=0; u<V; u++)
        for (int v=0; v<V; v++)
            if (path[u][v] == 1)
                printf("%d -> %d\n", u, v);
}

void printSolution(int dist[][V+1]) {
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V+1], path[V][V+1];

    for (int i=0; i<V; i++)
        for (int j=0; j<V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] == INF || i == j)
                path[i][j] = 0;
            else
                path[i][j] = 1;
        }

    for (int k=0; k<V; k++)
        for (int i=0; i<V; i++)
            for (int j=0; j<V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k]*path[k][j];
                }

    printSolution(dist);
    printPath(path);
}

int main() {
    int graph[V][V] = { {0, 3, INF, 7},
                        {8, 0, 2, INF},
                        {5, INF, 0, 1},
                        {2, INF, INF, 0}
                      };

    floydWarshall(graph);
    return 0;
}
