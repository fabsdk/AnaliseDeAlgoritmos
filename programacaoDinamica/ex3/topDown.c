#include <stdio.h>
#include <stdbool.h>

int dp[100][10000];

bool podeParticionar(int arr[], int n, int soma) {
    if (soma == 0)
        return true;
    if (n == 0 || soma < 0)
        return false;
    if (dp[n][soma] != -1)
        return dp[n][soma];

    bool incluir = podeParticionar(arr, n-1, soma-arr[n-1]);
    bool naoIncluir = podeParticionar(arr, n-1, soma);

    return dp[n][soma] = incluir || naoIncluir;
}

int main() {
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += arr[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= soma; j++)
            dp[i][j] = -1;

    if (soma % 2 == 0 && podeParticionar(arr, n, soma/2) == true)
        printf("Pode ser particionado em dois subconjuntos de soma igual\n");
    else
        printf("Não pode ser particionado em dois subconjuntos de soma igual\n");

    return 0;
}
