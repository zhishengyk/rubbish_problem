#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 一个正整数n是2的整数次幂，当且仅当 n > 0 且 (n & (n - 1)) == 0
    if (n > 0 && (n & (n - 1)) == 0) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
