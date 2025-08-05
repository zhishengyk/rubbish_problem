#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n + 1, 0);
    std::vector<long long> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << prefix_sum[r] - prefix_sum[l - 1] << std::endl;
    }

    return 0;
}
