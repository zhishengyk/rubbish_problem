#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    std::vector<int> white_cost(n, 0), blue_cost(n, 0), red_cost(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 'W') white_cost[i]++;
            if (grid[i][j] != 'B') blue_cost[i]++;
            if (grid[i][j] != 'R') red_cost[i]++;
        }
    }

    int min_cost = n * m;

    // 枚举白色区域的结束行（i）和蓝色区域的结束行（j）
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int current_cost = 0;
            // 计算白色区域的成本
            for (int k = 0; k <= i; ++k) {
                current_cost += white_cost[k];
            }
            // 计算蓝色区域的成本
            for (int k = i + 1; k <= j; ++k) {
                current_cost += blue_cost[k];
            }
            // 计算红色区域的成本
            for (int k = j + 1; k < n; ++k) {
                current_cost += red_cost[k];
            }
            min_cost = std::min(min_cost, current_cost);
        }
    }

    std::cout << min_cost << std::endl;

    return 0;
}
