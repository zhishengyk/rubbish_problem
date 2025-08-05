#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    // 1. 计算并输出整数部分
    int integer_part = n / m;
    std::cout << integer_part << ".";

    // 2. 计算初始余数
    int remainder = n % m;

    // 3. 循环计算100位小数
    for (int i = 0; i < 100; ++i) {
        // 将余数扩大10倍
        remainder *= 10;
        
        // 计算当前位的小数
        int digit = remainder / m;
        std::cout << digit;
        
        // 更新余数
        remainder %= m;
    }

    std::cout << std::endl;

    return 0;
}
