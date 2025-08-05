#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int max_sum = -1e9; // Initialize with a very small number

    for (int c1 = 0; c1 < n; ++c1) {
        std::vector<int> row_sum(n, 0);
        for (int c2 = c1; c2 < n; ++c2) {
            for (int r = 0; r < n; ++r) {
                row_sum[r] += matrix[r][c2];
            }

            // Kadane's algorithm for 1D array (row_sum)
            int current_max = 0;
            int global_max = -1e9;
            for (int val : row_sum) {
                current_max += val;
                if (current_max > global_max) {
                    global_max = current_max;
                }
                if (current_max < 0) {
                    current_max = 0;
                }
            }
            if (global_max > max_sum) {
                max_sum = global_max;
            }
        }
    }

    std::cout << max_sum << std::endl;

    return 0;
}
