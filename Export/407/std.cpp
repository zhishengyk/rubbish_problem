#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }

    // 使用std::sort进行排序
    std::sort(scores.begin(), scores.end());

    // 输出排序后的序列
    for (int i = 0; i < n; ++i) {
        std::cout << scores[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
