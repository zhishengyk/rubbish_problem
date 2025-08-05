#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> a(n);
    int max_val = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == max_val) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 0;
        }
    }
    // Final check for the last sequence
    max_length = std::max(max_length, current_length);
    
    std::cout << max_length << std::endl;

    return 0;
}
