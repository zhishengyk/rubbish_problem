#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long min_ops = -1;

    // 枚举最终要变成的目标数字（0到9）
    for (int target = 0; target <= 9; ++target) {
        long long current_total_ops = 0;
        // 计算将所有元素都变成target的总操作次数
        for (int x : a) {
            current_total_ops += (target - x + 10) % 10;
        }

        if (min_ops == -1 || current_total_ops < min_ops) {
            min_ops = current_total_ops;
        }
    }

    std::cout << min_ops << std::endl;

    return 0;
}
