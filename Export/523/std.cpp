#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    long long k;
    std::cin >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    if (k <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long count = 0;
    long long current_product = 1;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_product *= nums[right];
        
        while (current_product >= k && left <= right) {
            current_product /= nums[left];
            left++;
        }
        
        count += (right - left + 1);
    }

    std::cout << count << std::endl;

    return 0;
}
