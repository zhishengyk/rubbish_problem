#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long max_sum_limit, int n, int m, const std::vector<int>& a) {
    int segments_count = 1;
    long long current_sum = 0;
    for (int x : a) {
        if (x > max_sum_limit) return false; // Single element exceeds limit
        if (current_sum + x <= max_sum_limit) {
            current_sum += x;
        } else {
            segments_count++;
            current_sum = x;
        }
    }
    return segments_count <= m;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    long long total_sum = 0;
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_sum += a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    long long left = max_val, right = total_sum, ans = total_sum;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n, m, a)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
