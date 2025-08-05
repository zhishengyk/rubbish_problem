#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// a / b
std::string divide(const std::string& a, long long b) {
    if (b == 0) {
        // Handle division by zero, though problem constraints might prevent this.
        return "Error: Division by zero";
    }

    std::string quotient;
    long long remainder = 0;
    
    for (char c : a) {
        remainder = remainder * 10 + (c - '0');
        quotient.push_back(remainder / b + '0');
        remainder %= b;
    }
    
    // 去除前导零
    size_t first_digit_pos = 0;
    while (first_digit_pos < quotient.length() - 1 && quotient[first_digit_pos] == '0') {
        first_digit_pos++;
    }
    
    return quotient.substr(first_digit_pos);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a;
    long long b;
    std::cin >> a >> b;

    std::cout << divide(a, b) << std::endl;

    return 0;
}
