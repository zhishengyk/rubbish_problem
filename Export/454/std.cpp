#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    std::vector<int> result(num1.length() + num2.length(), 0);

    for (size_t i = 0; i < num1.length(); ++i) {
        for (size_t j = 0; j < num2.length(); ++j) {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    int carry = 0;
    for (size_t i = 0; i < result.size(); ++i) {
        int current_val = result[i] + carry;
        result[i] = current_val % 10;
        carry = current_val / 10;
    }

    // 找到最高位
    size_t first_digit_pos = result.size() - 1;
    while (first_digit_pos > 0 && result[first_digit_pos] == 0) {
        first_digit_pos--;
    }

    std::string res_str;
    for (int i = first_digit_pos; i >= 0; --i) {
        res_str.push_back(result[i] + '0');
    }

    return res_str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b;
    std::cin >> a >> b;

    std::cout << multiply(a, b) << std::endl;

    return 0;
}
