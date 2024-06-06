#include <stdio.h>
#include <stdbool.h>

#define V 5

void printSolution(int path[]) {
    printf("Ciclo Hamiltoniano encontrado: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}

bool hamiltonianCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]]) {
            return true;
        }
        else {
            return false;
        }
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1) == true) {
                return true;
            }
            path[pos] = -1; 
        }
    }
    return false;
}

bool hamiltonianCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    // Colocar o primeiro vértice no caminho
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1) == false) {
        printf("Não existe ciclo Hamiltoniano\n");
        return false;
    }
    printSolution(path);
    return true;
}

int main() {
    /* Grafo de exemplo
       (0)--(1)--(2)
        |   / \   |
        |  /   \  |
        | /     \ |
       (3)-------(4) 
    */
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    hamiltonianCycle(graph);
    return 0;
}
