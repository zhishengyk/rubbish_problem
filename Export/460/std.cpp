#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char to_char(int d) {
    if (d >= 0 && d <= 9) {
        return d + '0';
    }
    return d - 10 + 'A';
}

bool is_palindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
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

    int n;
    std::string m;
    std::cin >> n >> m;

    for (int steps = 0; steps <= 30; ++steps) {
        if (is_palindrome(m)) {
            std::cout << steps << std::endl;
            return 0;
        }
        if (steps == 30) {
            break;
        }
        std::string m_rev = m;
        std::reverse(m_rev.begin(), m_rev.end());
        m = add_in_base(m, m_rev, n);
    }

    std::cout << "Impossible" << std::endl;

    return 0;
}
