#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 比较两个正整数 represented by string
int compare(const std::string& a, const std::string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

// 高精度减法
std::string subtract(std::string a, std::string b) {
    if (compare(a, b) == -1) {
        std::swap(a, b);
    }

    std::string res;
    int borrow = 0;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (size_t i = 0; i < a.length(); ++i) {
        int num1 = a[i] - '0';
        int num2 = (i < b.length()) ? b[i] - '0' : 0;
        int diff = num1 - num2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff + '0');
    }
    while (res.length() > 1 && res.back() == '0') {
        res.pop_back();
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// 十进制转十六进制
std::string to_hex(unsigned long long n) {
    if (n == 0) return "0";
    std::string hex_str;
    const char hex_digits[] = "0123456789ABCDEF";
    while (n > 0) {
        hex_str.push_back(hex_digits[n % 16]);
        n /= 16;
    }
    std::reverse(hex_str.begin(), hex_str.end());
    return hex_str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b;
    std::cin >> a >> b;

    std::string diff_str = subtract(a, b);
    
    unsigned long long diff_val = std::stoull(diff_str);
    
    std::cout << to_hex(diff_val) << std::endl;

    return 0;
}
