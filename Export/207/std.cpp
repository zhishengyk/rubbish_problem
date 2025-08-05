#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }

    long long avg = sum / n;
    int moves = 0;

    // 将每堆牌的数量转换为与平均数的差值
    for (int i = 0; i < n; ++i) {
        a[i] -= avg;
    }

    // 从左到右遍历，依次平衡每一堆
    // 第 i 堆的不平衡量会转移到第 i+1 堆
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != 0) {
            // 只要第 i 堆不为0，就必须和右边进行一次移动
            moves++;
            // 将不平衡量转移
            a[i+1] += a[i];
            // a[i]在逻辑上变为0
        }
    }

    // 最后一堆 a[n-1] 必定为0，因为总和为0

    std::cout << moves << std::endl;

    return 0;
}
