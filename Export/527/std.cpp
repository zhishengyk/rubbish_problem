#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int counts[4] = {0};
    int left = 0;
    int min_length = std::numeric_limits<int>::max();
    int distinct_count = 0;

    for (int right = 0; right < n; ++right) {
        int digit = s[right] - '0';
        if (counts[digit] == 0) {
            distinct_count++;
        }
        counts[digit]++;

        while (distinct_count == 3) {
            min_length = std::min(min_length, right - left + 1);

            int left_digit = s[left] - '0';
            counts[left_digit]--;
            if (counts[left_digit] == 0) {
                distinct_count--;
            }
            left++;
        }
    }

    if (min_length == std::numeric_limits<int>::max()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << min_length << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
