#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 将十进制数转换为指定进制的字符串
std::string to_base_string(long long n, int base) {
    if (n == 0) {
        return "0";
    }
    std::string result = "";
    while (n > 0) {
        int remainder = n % base;
        // 本题进制范围最大11，不需要处理A-F
        result += std::to_string(remainder);
        n /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// 判断字符串是否是回文
bool is_palindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b;
    int c, d;
    std::cin >> a >> b >> c >> d;

    int total_valid_numbers = 0;
    for (long long i = a; i <= b; ++i) {
        long long square = i * i;
        int palindrome_base_count = 0;

        for (int base = c; base <= d; ++base) {
            std::string s_in_base = to_base_string(square, base);
            if (is_palindrome(s_in_base)) {
                palindrome_base_count++;
            }
        }

        if (palindrome_base_count == 1) {
            total_valid_numbers++;
        }
    }

    std::cout << total_valid_numbers << std::endl;

    return 0;
}
