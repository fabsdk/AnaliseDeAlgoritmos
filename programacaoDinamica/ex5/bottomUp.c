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

int wordBreak(char *s, const char *dictionary[], int dictSize) {
    int n = strlen(s);
    if (n == 0) return 0;

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Uma string vazia pode ser segmentada de qualquer forma.

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            char substr[i - j + 1];
            strncpy(substr, s + j, i - j);
            substr[i - j] = '\0';

            if (dp[j] && isWordInDictionary(substr, dictionary, dictSize)) {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[n];
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
