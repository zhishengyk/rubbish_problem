#include <iostream>
#include <vector>
#include <algorithm>

bool check(int d, int k, const std::vector<int>& signs) {
    int added_count = 0;
    for (size_t i = 0; i < signs.size() - 1; ++i) {
        int dist = signs[i+1] - signs[i];
        if (dist > d) {
            added_count += (dist - 1) / d;
        }
    }
    return added_count <= k;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int l, n, k;
    std::cin >> l >> n >> k;

    std::vector<int> signs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> signs[i];
    }
    
    // Although the problem statement guarantees signs at 0 and L,
    // let's handle cases where they might not be in the input list explicitly for robustness.
    bool has_zero = false, has_l = false;
    for(int s : signs) {
        if (s == 0) has_zero = true;
        if (s == l) has_l = true;
    }
    if (!has_zero) signs.push_back(0);
    if (!has_l) signs.push_back(l);

    std::sort(signs.begin(), signs.end());
    // Remove duplicates that might arise from adding 0/L
    signs.erase(std::unique(signs.begin(), signs.end()), signs.end());

    int left = 1, right = l, ans = l;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == 0) { left = 1; continue; }
        if (check(mid, k, signs)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
