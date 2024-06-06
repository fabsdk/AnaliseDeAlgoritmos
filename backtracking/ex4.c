#include <stdio.h>
#include <stdbool.h>


#define V 4

void imprimirSolucao(int cor[]);

bool ehSeguro (int v, bool grafo[V][V], int cor[], int c)
{
    for (int i = 0; i < V; i++)
        if (grafo[v][i] && c == cor[i])
            return false;
    return true;
}

bool colorirGrafoUtil(bool grafo[V][V], int m, int cor[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (ehSeguro(v, grafo, cor, c))
        {
           cor[v] = c;

           if (colorirGrafoUtil (grafo, m, cor, v+1) == true)
             return true;

           cor[v] = 0;
        }
    }

    return false;
}

bool colorirGrafo(bool grafo[V][V], int m)
{
    int cor[V];
    for (int i = 0; i < V; i++)
       cor[i] = 0;

    if (colorirGrafoUtil(grafo, m, cor, 0) == false)
    {
      printf("Solução não existe");
      return false;
    }

    imprimirSolucao(cor);
    return true;
}

void imprimirSolucao(int cor[])
{
    printf("Solucao Existe:"
            " Seguem as cores atribuídas \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", cor[i]);
    printf("\n");
}

int main()
{
    bool grafo[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    colorirGrafo (grafo, m);
    return 0;
}
