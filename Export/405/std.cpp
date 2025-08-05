#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // 使用std::sort进行排序
    std::sort(numbers.begin(), numbers.end());

    // 输出排序后的序列
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
