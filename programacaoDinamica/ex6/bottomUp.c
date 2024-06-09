#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCoins(int **grid, int m, int n) {
    int dp[m][n];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;
    int **grid = (int **)malloc(m * sizeof(int *));
    grid[0] = (int []){0, 1, 2};
    grid[1] = (int []){3, 4, 8};
    grid[2] = (int []){5, 6, 7};

    printf("Numero maximo de moedas coletadas: %d\n", maxCoins(grid, m, n));

    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
