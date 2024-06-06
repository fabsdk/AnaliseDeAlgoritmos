#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 9

int minimaDistancia(int dist[], bool conjuntoSPT[]) {
    int min = INT_MAX, indice_min;
    for (int v = 0; v < V; v++)
        if (conjuntoSPT[v] == false && dist[v] <= min)
            min = dist[v], indice_min = v;
    return indice_min;
}

void imprimirSolucao(int dist[]) {
    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int grafo[V][V], int src) {
    int dist[V];
    bool conjuntoSPT[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, conjuntoSPT[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minimaDistancia(dist, conjuntoSPT);
        conjuntoSPT[u] = true;
        for (int v = 0; v < V; v++)
            if (!conjuntoSPT[v] && grafo[u][v] && dist[u] != INT_MAX
                && dist[u] + grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
    }
    imprimirSolucao(dist);
}

int main() {
    int grafo[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(grafo, 0);
    return 0;
}
