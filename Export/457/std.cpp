#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void divide(const std::string& n_str, int d, std::string& quotient, int& remainder) {
    long long rem = 0;
    
    for (char c : n_str) {
        rem = rem * 10 + (c - '0');
        quotient.push_back(rem / d + '0');
        rem %= d;
    }
    
    remainder = rem;

    // 去除前导零
    size_t first_digit_pos = 0;
    while (first_digit_pos < quotient.length() - 1 && quotient[first_digit_pos] == '0') {
        first_digit_pos++;
    }
    quotient = quotient.substr(first_digit_pos);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string n;
    std::cin >> n;

    std::string quotient;
    int remainder;
    
    divide(n, 13, quotient, remainder);

    std::cout << quotient << std::endl;
    std::cout << remainder << std::endl;

    return 0;
}
