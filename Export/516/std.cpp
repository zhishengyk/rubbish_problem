#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const long double PI = acos(-1.0);

bool check(long double volume, int n, int f, const std::vector<int>& radii) {
    if (volume < 1e-9) return true;
    int total_pieces = 0;
    for (int r : radii) {
        long double pie_volume = PI * r * r;
        total_pieces += floor(pie_volume / volume);
    }
    return total_pieces >= f + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, f;
    std::cin >> n >> f;

    std::vector<int> radii(n);
    int max_r = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> radii[i];
        if (radii[i] > max_r) {
            max_r = radii[i];
        }
    }

    long double left = 0, right = PI * max_r * max_r, ans = 0;
    for(int i = 0; i < 100; ++i) { // Iterate 100 times for precision
        long double mid = left + (right - left) / 2;
        if (check(mid, n, f, radii)) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;

    return 0;
}
