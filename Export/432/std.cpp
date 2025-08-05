#include <iostream>
#include <vector>

const int MOD = 12345;

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    // dp[i] 表示铺满 i x 3 路面的方案数
    std::vector<int> dp(n + 1);
    
    // Base cases
    dp[0] = 1;
    dp[1] = 1;

    // Recurrence
    for (int i = 2; i <= n; ++i) {
        // dp[i] = dp[i-1] (最后一行用1x1铺) + 2 * dp[i-2] (最后两行用2x3的块铺)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}
