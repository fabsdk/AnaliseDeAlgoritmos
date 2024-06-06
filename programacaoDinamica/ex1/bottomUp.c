#include <stdio.h>
#include <string.h>

int countWays(int n, int k) {
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    int total = k;
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++) {
        dp[i] = (k-1) * (dp[i-1] + dp[i-2]);
    }

    return dp[n];
}

int main() {
    int n = 3, k = 2;
    printf("Numero de maneiras: %d", countWays(n, k));
    return 0;
}
