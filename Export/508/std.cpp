#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long l, int n, int k, const std::vector<int>& woods) {
    if (l == 0) return true; // Avoid division by zero, can always get k pieces of length 0.
    long long total_pieces = 0;
    for (int wood_len : woods) {
        total_pieces += wood_len / l;
    }
    return total_pieces >= k;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> woods(n);
    long long max_l = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> woods[i];
        if (woods[i] > max_l) {
            max_l = woods[i];
        }
    }

    long long left = 1, right = max_l, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (mid == 0) { // Should not happen with left=1, but as a safeguard.
            left = 1;
            continue;
        }
        if (check(mid, n, k, woods)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
