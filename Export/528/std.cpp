#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n <= 2) {
        std::cout << n;
        return;
    }

    int max_length = 2;
    int current_length = 2;
    long long diff = a[1] - a[0];

    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i-1] == diff) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 2;
            diff = a[i] - a[i-1];
        }
    }
    
    max_length = std::max(max_length, current_length);
    
    std::cout << max_length;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        std::cout << "Case #" << i << ": ";
        solve();
        std::cout << std::endl;
    }

    return 0;
}
