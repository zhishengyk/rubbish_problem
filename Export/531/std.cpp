#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> height[i];
    }

    int left = 0;
    int right = n - 1;
    long long max_area = 0;

    while (left < right) {
        long long h = std::min(height[left], height[right]);
        long long w = right - left;
        long long current_area = h * w;
        if (current_area > max_area) {
            max_area = current_area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    std::cout << max_area << std::endl;

    return 0;
}
