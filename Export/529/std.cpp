#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long p;
    std::cin >> n >> p;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int max_len = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        // The condition is M <= m * p, where M = a[right], m = a[left]
        while (left < right && a[right] > a[left] * p) {
            left++;
        }
        // After the while loop, the window [left, right] is valid.
        max_len = std::max(max_len, right - left + 1);
    }

    // A single element is always a valid subsequence of length 1
    if (n > 0 && max_len == 0) {
        max_len = 1;
    }
    
    std::cout << max_len << std::endl;

    return 0;
}
