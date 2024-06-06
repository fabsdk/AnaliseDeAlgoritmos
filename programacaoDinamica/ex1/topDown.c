#include <stdio.h>
#include <string.h>

int countWaysUtil(int n, int k, int dp[]) {
    if (dp[n] != -1) {
        return dp[n];
    }

    int same = k * dp[n-1];
    int diff = k * (dp[n-1] - dp[n-2]);

    dp[n] = same + diff;

    return dp[n];
}

int countWays(int n, int k) {
    int dp[n+1];
    memset(dp, -1, sizeof(dp));

    dp[1] = k;
    dp[2] = k * k;

    return countWaysUtil(n, k, dp);
}

int main() {
    int n = 3, k = 2;
    printf("Numero de maneiras: %d", countWays(n, k));
    return 0;
}
