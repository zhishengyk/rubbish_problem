#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums;
    int num;
    while (std::cin >> num && num != 0) {
        nums.push_back(num);
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
        std::cout << nums[i] << (i == 0 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
