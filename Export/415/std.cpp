#include <iostream>
#include <map>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 使用std::map来统计每个数字出现的次数
    // map会自动按键（自然数）从小到大排序
    std::map<int, int> counts;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        counts[num]++;
    }

    // 遍历map并输出结果
    for (const auto& pair : counts) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
