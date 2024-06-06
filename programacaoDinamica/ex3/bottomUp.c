#include <stdio.h>
#include <stdbool.h>

bool podeParticionar(int arr[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += arr[i];

    if (soma % 2 != 0)
        return false;

    bool dp[n+1][soma/2 + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= soma/2; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= soma/2; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][soma/2];
}

int main() {
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    if (podeParticionar(arr, n) == true)
        printf("Pode ser particionado em dois subconjuntos de soma igual\n");
    else
        printf("Não pode ser particionado em dois subconjuntos de soma igual\n");

    return 0;
}
