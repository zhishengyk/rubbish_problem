#include <iostream>
#include <cmath>

bool check(long long x, int n) {
    if (x == 0) return false;
    // We need floor(x * log10(x)) + 1 >= n
    // which is x * log10(x) >= n - 1
    return x * log10((long double)x) >= (long double)n - 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long left = 1, right = 2000000000, ans = right; 
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
