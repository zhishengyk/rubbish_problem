#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long t, int n, int a, int b, const std::vector<int>& w) {
    long long natural_dry = t * a;
    long long machine_capacity = t * b;
    long long needed_machine_dry = 0;

    for (int humidity : w) {
        if (humidity > natural_dry) {
            needed_machine_dry += (long long)humidity - natural_dry;
        }
    }

    return needed_machine_dry <= machine_capacity;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> w(n);
    int max_w = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
        if (w[i] > max_w) {
            max_w = w[i];
        }
    }

    long long left = 1, right = (max_w + a - 1) / a, ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n, a, b, w)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
