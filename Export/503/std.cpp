#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    long long c;
    std::cin >> n >> c;

    std::vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        long long target = nums[i] + c;
        auto lower = std::lower_bound(nums.begin() + i + 1, nums.end(), target);
        auto upper = std::upper_bound(nums.begin() + i + 1, nums.end(), target);
        count += std::distance(lower, upper);
    }

    std::cout << count << std::endl;

    return 0;
}
