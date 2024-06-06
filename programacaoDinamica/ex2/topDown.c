#include <stdio.h>

#define MAX_TAREFAS 100
#define MAX_RECURSOS 100

int max(int a, int b) { return (a > b)? a : b; }

int dp[MAX_TAREFAS][MAX_RECURSOS];

int alocacaoRecursos(int beneficio[], int custo[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;
    if (dp[n][W] != -1)
        return dp[n][W];
    if (custo[n-1] > W)
        return (dp[n][W] = alocacaoRecursos(beneficio, custo, n-1, W));
    else
        return (dp[n][W] = max(alocacaoRecursos(beneficio, custo, n-1, W),
                               beneficio[n-1] + alocacaoRecursos(beneficio, custo, n-1, W-custo[n-1])));
}

int main() {
    int beneficio[] = {60, 100, 120};
    int custo[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(beneficio)/sizeof(beneficio[0]);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=W; j++)
            dp[i][j] = -1;
    printf("Beneficio maximo: %d", alocacaoRecursos(beneficio, custo, n, W));
    return 0;
}
