#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar recursiva com memorização
int maxCoinsHelper(int **grid, int m, int n, int i, int j, int **memo) {
    if (i >= m || j >= n) return 0; 
    if (memo[i][j] != -1) return memo[i][j]; 

    int right = maxCoinsHelper(grid, m, n, i, j + 1, memo);
    int down = maxCoinsHelper(grid, m, n, i + 1, j, memo);

    memo[i][j] = grid[i][j] + (right > down ? right : down);
    return memo[i][j];
}

int maxCoins(int **grid, int m, int n) {
    int **memo = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        memo[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            memo[i][j] = -1; 
        }
    }

    int result = maxCoinsHelper(grid, m, n, 0, 0, memo);

    for (int i = 0; i < m; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
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
