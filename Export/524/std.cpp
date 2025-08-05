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

    // Sort the array to use binary search
    std::sort(nums.begin(), nums.end());

    long long count = 0;

    for (int i = 0; i < n; ++i) {
        long long target = nums[i] + c;
        
        // Find the first element not less than target
        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        
        // Find the first element greater than target
        auto upper = std::upper_bound(nums.begin(), nums.end(), target);
        
        // The distance between these two iterators is the number of occurrences of target
        count += std::distance(lower, upper);
    }

    std::cout << count << std::endl;

    return 0;
}
