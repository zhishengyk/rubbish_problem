#include <iostream>

// 函数：计算 (base^exp) % mod
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        // 如果指数是奇数，将base乘入结果
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        // 底数平方
        base = (base * base) % mod;
        // 指数除以2
        exp /= 2;
    }
    return res;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    std::cin >> a >> b;

    std::cout << power(a, b) << std::endl;

    return 0;
}
