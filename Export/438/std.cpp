#include <iostream>
#include <vector>

const int MOD = 12345;

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // dp[i][0] will store the count of i-digit numbers with an even number of 3s.
    // dp[i][1] will store the count of i-digit numbers with an odd number of 3s.
    // The first digit cannot be 0.
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2, 0));

    // Base case: 1-digit numbers
    // Numbers are 1, 2, ..., 9
    // Even number of 3s: 1, 2, 4, 5, 6, 7, 8, 9 (8 numbers)
    // Odd number of 3s: 3 (1 number)
    dp[1][0] = 8;
    dp[1][1] = 1;

    // Fill DP table for i from 2 to n
    for (int i = 2; i <= n; ++i) {
        // To form an i-digit number with an even number of 3s:
        // 1. Take an (i-1)-digit number with an even number of 3s (dp[i-1][0] ways)
        //    and append a digit that is not 3. There are 9 such digits (0,1,2,4,5,6,7,8,9).
        //    Total ways: dp[i-1][0] * 9
        // 2. Take an (i-1)-digit number with an odd number of 3s (dp[i-1][1] ways)
        //    and append the digit 3.
        //    Total ways: dp[i-1][1] * 1
        dp[i][0] = (dp[i - 1][0] * 9 + dp[i - 1][1]) % MOD;

        // To form an i-digit number with an odd number of 3s:
        // 1. Take an (i-1)-digit number with an even number of 3s (dp[i-1][0] ways)
        //    and append the digit 3.
        //    Total ways: dp[i-1][0] * 1
        // 2. Take an (i-1)-digit number with an odd number of 3s (dp[i-1][1] ways)
        //    and append a digit that is not 3. There are 9 such digits.
        //    Total ways: dp[i-1][1] * 9
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 9) % MOD;
    }

    std::cout << dp[n][0] << std::endl;

    return 0;
}
