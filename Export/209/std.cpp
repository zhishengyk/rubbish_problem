#include <iostream>
#include <vector>
#include <algorithm>

// 使用递归实现，天然倒序输出
void solve(int n) {
    if (n == 1) {
        std::cout << 1;
        return;
    }

    if (n % 2 == 0) {
        solve(n / 2);
    } else {
        solve(3 * n + 1);
    }
    
    // 在递归返回后输出当前值
    std::cout << " " << n;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    solve(n);
    std::cout << std::endl;

    return 0;
}
