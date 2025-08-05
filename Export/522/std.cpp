#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    long long s;
    std::cin >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int min_length = std::numeric_limits<int>::max();
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];

        while (current_sum >= s) {
            min_length = std::min(min_length, right - left + 1);
            current_sum -= a[left];
            left++;
        }
    }

    if (min_length == std::numeric_limits<int>::max()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << min_length << std::endl;
    }

    return 0;
}
