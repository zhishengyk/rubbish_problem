#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> counts(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> counts[i];
    }

    std::string result = "";

    // 找到最小的非零数字作为首位
    for (int i = 1; i < 10; ++i) {
        if (counts[i] > 0) {
            result += std::to_string(i);
            counts[i]--;
            break;
        }
    }

    // 拼接剩余的数字
    for (int i = 0; i < 10; ++i) {
        result += std::string(counts[i], '0' + i);
    }

    std::cout << result << std::endl;

    return 0;
}
