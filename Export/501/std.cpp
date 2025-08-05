#include <iostream>
#include <vector>
#include <algorithm>

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

    std::sort(nums.begin(), nums.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        long long sum = (long long)nums[left] + nums[right];
        if (sum == m) {
            std::cout << nums[left] << " " << nums[right] << std::endl;
            return 0;
        } else if (sum < m) {
            left++;
        } else {
            right--;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}
