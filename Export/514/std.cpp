#include <iostream>
#include <vector>
#include <algorithm>

bool check(int d, int n, int c, const std::vector<int>& stalls) {
    int cows_placed = 1;
    int last_pos = stalls[0];
    for (int i = 1; i < n; ++i) {
        if (stalls[i] - last_pos >= d) {
            cows_placed++;
            last_pos = stalls[i];
            if (cows_placed >= c) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, c;
    std::cin >> n >> c;

    std::vector<int> stalls(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> stalls[i];
    }

    std::sort(stalls.begin(), stalls.end());

    int left = 1, right = stalls[n-1] - stalls[0], ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, n, c, stalls)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
