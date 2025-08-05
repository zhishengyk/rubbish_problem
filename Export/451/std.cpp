#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// 函数用于实现高精度加法
std::string add(std::string num1, std::string num2) {
    std::string sum = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int current_sum = digit1 + digit2 + carry;
        sum += std::to_string(current_sum % 10);
        carry = current_sum / 10;
    }

    std::reverse(sum.begin(), sum.end());
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string a, b;
    std::cin >> a >> b;
    std::cout << add(a, b) << std::endl;
    return 0;
}
