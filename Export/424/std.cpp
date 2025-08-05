#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned int n;
    std::cin >> n;

    int count = 0;
    while (n > 0) {
        // 每次执行 n & (n - 1) 都会将n的二进制表示中最低位的1变为0
        n = n & (n - 1);
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}
