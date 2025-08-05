#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string bin_num;
    std::cin >> bin_num;

    // 找到最右边的 '1'
    size_t last_one_pos = bin_num.rfind('1');

    // 如果找不到 '1' (输入是 "0" 或空字符串)，则其相反数的补码还是自身
    if (last_one_pos == std::string::npos) {
        std::cout << bin_num << std::endl;
        return 0;
    }

    // 从右到左，第一个'1'及其右边不变，左边全部取反
    for (size_t i = 0; i < last_one_pos; ++i) {
        if (bin_num[i] == '0') {
            bin_num[i] = '1';
        } else {
            bin_num[i] = '0';
        }
    }

    std::cout << bin_num << std::endl;

    return 0;
}
