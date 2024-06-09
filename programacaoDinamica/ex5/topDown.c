#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para verificar se uma palavra está no dicionário
int isWordInDictionary(const char *word, const char *dictionary[], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função auxiliar recursiva com memorização
int wordBreakHelper(char *s, const char *dictionary[], int dictSize, int start, int *memo) {
    int n = strlen(s);
    if (start == n) return 1; // Se chegamos ao final da string, a segmentação é válida
    if (memo[start] != -1) return memo[start]; // Retorna o resultado memorizado, se já calculado

    for (int end = start + 1; end <= n; end++) {
        char substr[end - start + 1];
        strncpy(substr, s + start, end - start);
        substr[end - start] = '\0';

        if (isWordInDictionary(substr, dictionary, dictSize) && wordBreakHelper(s, dictionary, dictSize, end, memo)) {
            memo[start] = 1;
            return 1;
        }
    }

    memo[start] = 0;
    return 0;
}

int wordBreak(char *s, const char *dictionary[], int dictSize) {
    int n = strlen(s);
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1; 

    return wordBreakHelper(s, dictionary, dictSize, 0, memo);
}

int main() {
    char s[] = "leetcode";
    const char *dictionary[] = {"leet", "code"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    if (wordBreak(s, dictionary, dictSize)) {
        printf("A string pode ser segmentada em palavras do dicionario.\n");
    } else {
        printf("A string NAO pode ser segmentada em palavras do dicionario.\n");
    }

    return 0;
}
