#include <stdio.h>
#include <string.h>

int numDecodings(char *s) {
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int dp[n + 1];
    dp[0] = 1; 
    dp[1] = s[0] != '0' ? 1 : 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        int oneDigit = s[i - 1] - '0';
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (oneDigit >= 1) {
            dp[i] += dp[i - 1];
        }

        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    char s[] = "226";
    printf("Numero de formas de decodificar: %d\n", numDecodings(s));
    return 0;
}
