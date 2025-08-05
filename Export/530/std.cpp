#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    long long k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int min_area = std::numeric_limits<int>::max();

    for (int top_row = 0; top_row < n; ++top_row) {
        std::vector<long long> col_sums(m, 0);
        for (int bottom_row = top_row; bottom_row < n; ++bottom_row) {
            // Update col_sums with the new bottom_row
            for (int j = 0; j < m; ++j) {
                col_sums[j] += matrix[bottom_row][j];
            }

            // Apply sliding window on the 1D array col_sums
            long long current_sum = 0;
            int left_col = 0;
            for (int right_col = 0; right_col < m; ++right_col) {
                current_sum += col_sums[right_col];
                
                while (current_sum >= k) {
                    int height = bottom_row - top_row + 1;
                    int width = right_col - left_col + 1;
                    min_area = std::min(min_area, height * width);
                    
                    current_sum -= col_sums[left_col];
                    left_col++;
                }
            }
        }
    }

    if (min_area == std::numeric_limits<int>::max()) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << min_area << std::endl;
    }

    return 0;
}
