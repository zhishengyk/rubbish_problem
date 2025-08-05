#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 判断字符串是否是回文
bool is_palindrome(const std::string& s) {
    if (s.empty()) {
        return true;
    }
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

// 辅助函数：将10-15的数字转换为'A'-'F'
char val_to_hex_char(int v) {
    if (v >= 0 && v <= 9) {
        return v + '0';
    } else {
        return v - 10 + 'A';
    }
}

// 将long long转换为指定进制的字符串
std::string to_base_string(long long n, int base) {
    if (n == 0) {
        return "0";
    }
    std::string result = "";
    while (n > 0) {
        int remainder = n % base;
        if (base == 16) {
            result += val_to_hex_char(remainder);
        } else { // base == 2
            result += std::to_string(remainder);
        }
        n /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        long long num;
        std::cin >> num;

        // 检查十进制是否是回文
        if (is_palindrome(std::to_string(num))) {
            continue; // 是十进制回文，不满足"半个回文数"定义
        }

        // 检查二进制或十六进制是否是回文
        if (is_palindrome(to_base_string(num, 2)) || is_palindrome(to_base_string(num, 16))) {
            std::cout << num << std::endl;
        }
    }

    return 0;
}
