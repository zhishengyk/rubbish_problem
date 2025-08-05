#include <iostream>
#include <string>
#include <algorithm>

// 函数：计算给定数字的二进制表示中1和0的数量
void countBits(int n, int& ones, int& zeros) {
    ones = 0;
    int total_bits = 0;
    
    if (n == 0) {
        zeros = 1; // 特殊情况处理数字0
        return;
    }

    int temp = n;
    while (temp > 0) {
        if (temp & 1) {
            ones++;
        }
        temp >>= 1;
        total_bits++;
    }
    zeros = total_bits - ones;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a_count = 0;
    int b_count = 0;

    for (int i = 1; i <= 10000; ++i) {
        int ones, zeros;
        countBits(i, ones, zeros);
        if (ones > zeros) {
            a_count++;
        } else {
            b_count++;
        }
    }

    std::cout << a_count << " " << b_count << std::endl;

    return 0;
}
