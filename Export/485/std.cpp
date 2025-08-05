#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long sum = 0;
    long long sum_sq = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
        sum_sq += a[i] * a[i];
    }

    long long result = (sum * sum - sum_sq) / 2;
    std::cout << result << std::endl;

    return 0;
}
