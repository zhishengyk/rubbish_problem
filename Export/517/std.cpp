#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n;
    std::cin >> n;

    double left = -100.0, right = 100.0;
    if (n < -1.0) right = -1.0;
    if (n > 1.0) left = 1.0;
    if (n > -1.0 && n < 1.0) {
        left = n > 0 ? 0 : -1.0;
        right = n > 0 ? 1.0 : 0;
    }


    for(int i = 0; i < 100; ++i) {
        double mid = left + (right - left) / 2;
        if (mid * mid * mid > n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << left << std::endl;

    return 0;
}
