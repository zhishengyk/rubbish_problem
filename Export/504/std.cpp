#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;

        auto it = std::lower_bound(nums.begin(), nums.end(), x);

        if (it == nums.begin()) {
            std::cout << *it << std::endl;
        } else if (it == nums.end()) {
            std::cout << *(it - 1) << std::endl;
        } else {
            int val1 = *(it - 1);
            int val2 = *it;
            if (x - val1 <= val2 - x) {
                std::cout << val1 << std::endl;
            } else {
                std::cout << val2 << std::endl;
            }
        }
    }

    return 0;
}
