#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<std::vector<long long>> prefix_sum(n + 1, std::vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long val;
            std::cin >> val;
            prefix_sum[i][j] = val + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    long long max_sum = -2e18; // Initialize with a very small number
    int max_x = -1, max_y = -1;

    for (int i = 1; i <= n - c + 1; ++i) {
        for (int j = 1; j <= m - c + 1; ++j) {
            int x2 = i + c - 1;
            int y2 = j + c - 1;
            long long current_sum = prefix_sum[x2][y2] - prefix_sum[i - 1][y2] - prefix_sum[x2][j - 1] + prefix_sum[i - 1][j - 1];
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_x = i;
                max_y = j;
            }
        }
    }

    std::cout << max_x << " " << max_y << std::endl;

    return 0;
}
