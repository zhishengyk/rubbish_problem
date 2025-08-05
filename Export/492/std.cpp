#include <iostream>
#include <vector>
#include <iomanip>

bool check(double avg, int n, int L, const std::vector<int>& a) {
    std::vector<double> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i-1] - avg;
    }

    std::vector<double> prefix_sum_b(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum_b[i] = prefix_sum_b[i - 1] + b[i];
    }

    double min_prefix = 0;
    for (int j = L; j <= n; ++j) {
        min_prefix = std::min(min_prefix, prefix_sum_b[j - L]);
        if (prefix_sum_b[j] >= min_prefix) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, L;
    std::cin >> n >> L;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    double left = 0, right = 1e9;
    for(int i = 0; i < 100; ++i) { // Binary search for 100 iterations for precision
        double mid = left + (right - left) / 2;
        if (check(mid, n, L, a)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << static_cast<int>(left * 1000) << std::endl;

    return 0;
}
