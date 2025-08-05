#include <iostream>
#include <vector>

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // dp[i] will store the number of ways to tile a 1 x i rectangle.
    std::vector<long long> dp(n + 1, 0);

    // Base cases
    dp[0] = 1; // There's one way to tile a 1x0 rectangle (do nothing)
    if (n >= 1) {
        dp[1] = 1; // Tile with one 1x1
    }
    if (n >= 2) {
        dp[2] = 2; // Two 1x1s, or one 1x2
    }
     if (n >= 3) {
        dp[3] = 4; // As given in the example
    }

    // Fill DP table using the recurrence relation
    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i-3];
    }

    std::cout << dp[n] << std::endl;

    return 0;
}
