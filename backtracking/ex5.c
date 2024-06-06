#include <stdio.h>

void printSequence(int sequence[], int n) {
    printf("Sequencia: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int isValid(int sequence[], int n, int m) {
    for (int i = 1; i < n; i++) {
        if (sequence[i] == sequence[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void generateSequences(int sequence[], int index, int n, int m) {
    if (index == n) {
        // Se a sequência estiver completa
        if (isValid(sequence, n, m)) {
            printSequence(sequence, n);
        }
        return;
    }

    // Tentar adicionar cada cor possível na posição atual
    for (int i = 1; i <= m; i++) {
        sequence[index] = i;
        generateSequences(sequence, index + 1, n, m);
    }
}

int main() {
    int n, m;
    printf("Digite o tamanho da sequencia (n): ");
    scanf("%d", &n);
    printf("Digite o numero de cores (m): ");
    scanf("%d", &m);

    int sequence[n];

    generateSequences(sequence, 0, n, m);

    return 0;
}
