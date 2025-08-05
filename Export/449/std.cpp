#include <iostream>

/**
 * @brief Recursively counts the number of valid numbers that can be formed.
 * 
 * Let f(n) be the number of ways to form a valid sequence starting with n.
 * A sequence can be just "n" itself (1 way).
 * Or, we can prepend a number k (where 1 <= k <= n/2) to the left of n.
 * After prepending k, the new number becomes "kn", and we need to find the number
 * of ways to form a valid sequence starting from k. This is f(k).
 * So, f(n) = 1 (for the number n itself) + sum(f(k) for k from 1 to n/2).
 * 
 * @param n The current number to process.
 * @return The number of ways that can be formed starting from n.
 */
int count_ways(int n) {
    // 1 way for the number n itself.
    int total_ways = 1;

    // Iterate through all possible numbers 'k' that can be prepended.
    for (int k = 1; k <= n / 2; ++k) {
        // For each k, we recursively find the number of ways starting with k.
        total_ways += count_ways(k);
    }
    
    return total_ways;
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Using a DP array to store results of subproblems (memoization)
    // would be much more efficient than pure recursion.
    // Let's implement the DP version.

    std::vector<int> dp(n + 1, 0);

    // dp[i] will store the number of ways for the number i.
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1; // For the number i itself
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] += dp[j];
        }
    }

    std::cout << dp[n] << std::endl;

    return 0;
}
