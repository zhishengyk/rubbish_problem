#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 价格范围是0-1000，所以我们需要一个大小为1001的桶
    std::vector<int> counts(1001, 0);

    // 读取价格并计数
    for (int i = 0; i < n; ++i) {
        int price;
        std::cin >> price;
        if (price >= 0 && price <= 1000) {
            counts[price]++;
        }
    }

    // 按顺序输出价格
    for (int price = 0; price <= 1000; ++price) {
        for (int i = 0; i < counts[price]; ++i) {
            std::cout << price << "\n";
        }
    }

    return 0;
}
