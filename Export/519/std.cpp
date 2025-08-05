#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Stop {
    int x, y, s;
};

bool check(double v, int n, const std::vector<Stop>& stops) {
    if (v < 1e-9) return false;
    double current_time = 0;
    for (int i = 0; i < n; ++i) {
        double travel_time = stops[i].s / v;
        current_time += travel_time;
        if (current_time > stops[i].y) {
            return false;
        }
        if (current_time < stops[i].x) {
            current_time = stops[i].x;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Stop> stops(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> stops[i].x >> stops[i].y >> stops[i].s;
    }

    double left = 0, right = 2e7, ans = right; // A sufficiently large upper bound for speed
    for (int i = 0; i < 100; ++i) {
        double mid = left + (right - left) / 2;
        if (check(mid, n, stops)) {
            ans = mid;
            right = mid;
        } else {
            left = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;

    return 0;
}
