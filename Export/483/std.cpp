#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n + 1, 0);
    std::vector<long long> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << prefix_sum[r] - prefix_sum[l - 1] << std::endl;
    }

    return 0;
}
