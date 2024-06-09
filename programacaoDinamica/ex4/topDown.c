#include <stdio.h>
#include <string.h>

int decodeWays(char *s, int n, int *memo) {
    if (n == 0) return 1;
    if (s[0] == '0') return 0;

    if (memo[n] != -1) return memo[n]; 

    int result = decodeWays(s + 1, n - 1, memo); 
    if (n >= 2 && ((s[0] == '1') || (s[0] == '2' && s[1] <= '6'))) {
        result += decodeWays(s + 2, n - 2, memo);
    }

    memo[n] = result;
    return result;
}

int numDecodings(char *s) {
    int n = strlen(s);
    int memo[n + 1];
    for (int i = 0; i <= n; i++) memo[i] = -1;

    return decodeWays(s, n, memo);
}

int main() {
    char s[] = "226";
    printf("Numero de formas de decodificar: %d\n", numDecodings(s));
    return 0;
}
