#include <stdio.h>
#include <string.h>

#define N 10
#define WORDS 5

char board[N][N];
char *words[WORDS] = {"word", "cross", "puzzle", "example", "solve"};

void initializeBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int canPlaceWordHorizontally(char *word, int row, int col) {
    int len = strlen(word);
    if (col + len > N) return 0;
    for (int i = 0; i < len; i++) {
        if (board[row][col + i] != '.' && board[row][col + i] != word[i]) {
            return 0;
        }
    }
    return 1;
}

int canPlaceWordVertically(char *word, int row, int col) {
    int len = strlen(word);
    if (row + len > N) return 0;
    for (int i = 0; i < len; i++) {
        if (board[row + i][col] != '.' && board[row + i][col] != word[i]) {
            return 0;
        }
    }
    return 1;
}

void placeWordHorizontally(char *word, int row, int col) {
    for (int i = 0; i < strlen(word); i++) {
        board[row][col + i] = word[i];
    }
}

void placeWordVertically(char *word, int row, int col) {
    for (int i = 0; i < strlen(word); i++) {
        board[row + i][col] = word[i];
    }
}

void removeWordHorizontally(char *word, int row, int col) {
    for (int i = 0; i < strlen(word); i++) {
        board[row][col + i] = '.';
    }
}

void removeWordVertically(char *word, int row, int col) {
    for (int i = 0; i < strlen(word); i++) {
        board[row + i][col] = '.';
    }
}

int solveCrossword(int wordIndex) {
    if (wordIndex == WORDS) {
        return 1;
    }

    char *word = words[wordIndex];

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (canPlaceWordHorizontally(word, row, col)) {
                placeWordHorizontally(word, row, col);
                if (solveCrossword(wordIndex + 1)) {
                    return 1;
                }
                removeWordHorizontally(word, row, col);
            }
            if (canPlaceWordVertically(word, row, col)) {
                placeWordVertically(word, row, col);
                if (solveCrossword(wordIndex + 1)) {
                    return 1;
                }
                removeWordVertically(word, row, col);
            }
        }
    }

    return 0;
}

int main() {
    initializeBoard();
    if (solveCrossword(0)) {
        printBoard();
    } else {
        printf("Nenhuma solução encontrada\n");
    }
    return 0;
}
