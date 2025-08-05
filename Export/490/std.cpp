#include <iostream>
#include <vector>
#include <numeric>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_sum += a[i];
    }

    if (total_sum % 3 != 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    if (n < 3) {
        std::cout << "NO" << std::endl;
        return;
    }

    long long target_sum = total_sum / 3;
    std::vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        if (prefix_sum[i] == target_sum) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (prefix_sum[j] - prefix_sum[i] == target_sum) {
                    std::cout << "YES" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "NO" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
