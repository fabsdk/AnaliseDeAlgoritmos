#include <stdio.h>
#include <stdbool.h>

#define N 3
#define SUM 15

int square[N][N];
bool used[10];

bool isMagicSquare() {
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < N; i++) {
        int sumRow = 0, sumColumn = 0;
        sumDiagonal1 += square[i][i];
        sumDiagonal2 += square[i][N - i - 1];
        for (int j = 0; j < N; j++) {
            sumRow += square[i][j];
            sumColumn += square[j][i];
        }
        if (sumRow != SUM || sumColumn != SUM) return false;
    }
    return sumDiagonal1 == SUM && sumDiagonal2 == SUM;
}

void printMagicSquare() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}

void magicSquare(int i, int j) {
    if (i == N) {
        if (isMagicSquare()) printMagicSquare();
        return;
    }
    if (j == N) {
        magicSquare(i + 1, 0);
        return;
    }
    for (int num = 1; num <= 9; num++) {
        if (!used[num]) {
            used[num] = true;
            square[i][j] = num;
            magicSquare(i, j + 1);
            used[num] = false;
        }
    }
}

int main() {
    magicSquare(0, 0);
    return 0;
}
