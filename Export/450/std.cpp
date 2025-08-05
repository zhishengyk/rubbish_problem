#include <iostream>

/**
 * @brief 计算将m个苹果放入n个盘子的方法数
 * @param m 苹果数量
 * @param n 盘子数量
 * @return 方法数
 */
int count(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    }
    if (m < n) {
        return count(m, m);
    }
    return count(m, n - 1) + count(m - n, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int m, n;
        std::cin >> m >> n;
        std::cout << count(m, n) << std::endl;
    }
    return 0;
}
