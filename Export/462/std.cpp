#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 高精度乘低精度 (int)
std::string multiply_by_int(std::string a, int b) {
    if (a == "0" || b == 0) return "0";
    if (b == 1) return a;

    std::string res;
    long long carry = 0;
    std::reverse(a.begin(), a.end());

    for (size_t i = 0; i < a.length() || carry; ++i) {
        long long num1 = (i < a.length()) ? a[i] - '0' : 0;
        long long product = num1 * b + carry;
        res.push_back(product % 10 + '0');
        carry = product / 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// 高精度减低精度 (int)
std::string subtract_int(std::string a, int b) {
    std::string res;
    int borrow = 0;
    std::reverse(a.begin(), a.end());

    int first_digit = a[0] - '0';
    if (first_digit >= b) {
        res.push_back((first_digit - b) + '0');
    } else {
        res.push_back((first_digit + 10 - b) + '0');
        borrow = 1;
    }

    for (size_t i = 1; i < a.length(); ++i) {
        int num = a[i] - '0' - borrow;
        if (num < 0) {
            num += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(num + '0');
    }

    while (res.length() > 1 && res.back() == '0') {
        res.pop_back();
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 计算 2^(n+1)
    std::string power_of_2 = "1";
    for (int i = 0; i < n + 1; ++i) {
        power_of_2 = multiply_by_int(power_of_2, 2);
    }
    
    // 减去 2
    std::string result = subtract_int(power_of_2, 2);

    std::cout << result << std::endl;

    return 0;
}
