#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, p;
    std::cin >> n >> p;

    std::vector<long long> a(n + 1);
    std::vector<long long> diff(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }

    for (int i = 0; i < p; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        diff[x] += z;
        if (y + 1 <= n) {
            diff[y + 1] -= z;
        }
    }

    long long min_score = 1e18; // Initialize with a very large number
    long long current_score = 0;
    for (int i = 1; i <= n; ++i) {
        current_score += diff[i];
        if (current_score < min_score) {
            min_score = current_score;
        }
    }

    std::cout << min_score << std::endl;

    return 0;
}
