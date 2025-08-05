#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long h, int n, long long m, const std::vector<int>& trees) {
    long long total_wood = 0;
    for (int tree_height : trees) {
        if (tree_height > h) {
            total_wood += (long long)tree_height - h;
        }
    }
    return total_wood >= m;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long m;
    std::cin >> n >> m;

    std::vector<int> trees(n);
    int max_h = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> trees[i];
        if (trees[i] > max_h) {
            max_h = trees[i];
        }
    }

    long long left = 0, right = max_h, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n, m, trees)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
