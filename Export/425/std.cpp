#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long sum_of_elements = 0;
    for (int i = 0; i < n; ++i) {
        long long element;
        std::cin >> element;
        sum_of_elements += element;
    }

    // 计算 2^(n-1)
    // 使用 1LL 保证位移操作在64位 long long 上进行，防止溢出
    long long power_of_2 = (1LL << (n - 1));

    // 计算总和
    long long total_sum = sum_of_elements * power_of_2;

    std::cout << total_sum << std::endl;

    return 0;
}
