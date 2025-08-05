#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; // 进制
    long long x; // n进制数
    std::cin >> n >> x;

    long long decimal_value = 0;
    long long power = 1;

    while (x > 0) {
        // 取出x的最低位
        int digit = x % 10;
        
        // 累加到十进制结果中
        decimal_value += digit * power;
        
        // 更新权重
        power *= n;
        
        // 去掉x的最低位
        x /= 10;
    }

    std::cout << decimal_value << std::endl;

    return 0;
}
