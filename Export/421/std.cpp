#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long k, n;
    std::cin >> k >> n;

    long long result = 0;
    long long power_of_k = 1;

    // 将 n 看作二进制数，用 k 进制的权来求值
    while (n > 0) {
        // 如果 n 的二进制最低位是 1
        if (n % 2 == 1) {
            // 加上对应的 k 的方幂
            result += power_of_k;
        }

        // 更新 k 的方幂
        power_of_k *= k;
        
        // n 右移一位，处理下一位
        n /= 2;
    }

    std::cout << result << std::endl;

    return 0;
}
