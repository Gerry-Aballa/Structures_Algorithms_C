#include <stdio.h>

// Approach 1: Recursive Function
int recursiveFib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return recursiveFib(n - 3) + recursiveFib(n - 2);
}

// Approach 2: Memoization (Top-Down Dynamic Programming)
int memoFib(int n, int memo[]) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (memo[n] != -1) return memo[n];
    memo[n] = memoFib(n - 3, memo) + memoFib(n - 2, memo);
    return memo[n];
}

// Approach 3: Iterative (Bottom-Up Dynamic Programming)
int iterativeFib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10; // Change n to the desired value

    // Approach 1
    printf("Approach 1: %d\n", recursiveFib(n));

    // Approach 2
    int memo[n + 1];
    for (int i = 0; i <= n; ++i) memo[i] = -1;
    printf("Approach 2: %d\n", memoFib(n, memo));

    // Approach 3
    printf("Approach 3: %d\n", iterativeFib(n));

    return 0;
}