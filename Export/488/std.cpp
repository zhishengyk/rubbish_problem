#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> diff(n + 2, std::vector<int>(n + 2, 0));

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y1]--;
        diff[x2 + 1][y2 + 1]++;
    }

    std::vector<std::vector<int>> result(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + diff[i][j];
            std::cout << result[i][j] << (j == n ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
