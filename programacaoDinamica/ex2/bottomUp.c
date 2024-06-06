#include <stdio.h>

#define MAX_TAREFAS 100
#define MAX_RECURSOS 100

int max(int a, int b) { return (a > b)? a : b; }

int alocacaoRecursos(int beneficio[], int custo[], int n, int W) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (custo[i-1] <= w)
                K[i][w] = max(beneficio[i-1] + K[i-1][w-custo[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main() {
    int beneficio[] = {60, 100, 120};
    int custo[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(beneficio)/sizeof(beneficio[0]);
    printf("Beneficio maximo: %d", alocacaoRecursos(beneficio, custo, n, W));
    return 0;
}
