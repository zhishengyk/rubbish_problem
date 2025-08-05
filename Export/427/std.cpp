#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        result ^= num; // 累积异或
    }

    std::cout << result << std::endl;

    return 0;
}
