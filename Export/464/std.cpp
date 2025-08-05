#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    // Assuming uppercase A-Z for bases > 10
    return c - 'A' + 10;
}

char to_char(int d) {
    if (d >= 0 && d <= 9) {
        return d + '0';
    }
    return d - 10 + 'A';
}

std::string add_in_base(std::string num1, std::string num2, int base) {
    std::string res;
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int carry = 0;

    for (size_t i = 0; i < num1.length() || i < num2.length() || carry; ++i) {
        int d1 = (i < num1.length()) ? to_digit(num1[i]) : 0;
        int d2 = (i < num2.length()) ? to_digit(num2[i]) : 0;
        int sum = d1 + d2 + carry;
        res.push_back(to_char(sum % base));
        carry = sum / base;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int b;
    std::string num1, num2;
    std::cin >> b >> num1 >> num2;

    std::cout << add_in_base(num1, num2, b) << std::endl;

    return 0;
}
