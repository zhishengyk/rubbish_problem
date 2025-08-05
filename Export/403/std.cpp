#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 使用std::set自动去重和排序
    std::set<int> unique_numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        unique_numbers.insert(num);
    }

    // 输出不相同随机数的个数
    std::cout << unique_numbers.size() << std::endl;

    // 输出排序后的不相同随机数
    bool first = true;
    for (int num : unique_numbers) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << num;
        first = false;
    }
    std::cout << std::endl;

    return 0;
}
