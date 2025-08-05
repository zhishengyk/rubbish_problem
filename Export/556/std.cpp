#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::sort(s.begin(), s.end());

    int max_diamonds = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        while (s[right] - s[left] > k) {
            left++;
        }
        max_diamonds = std::max(max_diamonds, right - left + 1);
    }

    std::cout << max_diamonds << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
