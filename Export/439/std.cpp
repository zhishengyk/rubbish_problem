#include <iostream>
#include <vector>

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // dp[i] will store the number of ways to tile a 2 x i rectangle.
    // This is equivalent to the (i+1)-th Fibonacci number if F_0=0, F_1=1.
    // Or F_i if F_1=1, F_2=2.
    std::vector<long long> dp(n + 1, 0);

    // Base cases
    if (n >= 1) {
        dp[1] = 1; // One way: two 1x2 tiles placed vertically
    }
    if (n >= 2) {
        dp[2] = 2; // Two ways: all vertical, or all horizontal
    }

    // Fill DP table using the recurrence relation: dp[i] = dp[i-1] + dp[i-2]
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Output the results from 1 to n
    for (int i = 1; i <= n; ++i) {
        std::cout << "x[" << i << "]=" << dp[i] << std::endl;
    }

    return 0;
}
