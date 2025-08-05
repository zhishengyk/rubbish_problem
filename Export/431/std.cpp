#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 将字符 ('0'-'9', 'a'-'z') 转换为对应的数值 (0-35)
int char_to_val(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else { // 'a' to 'z'
        return c - 'a' + 10;
    }
}

// 将数值 (0-35) 转换为对应的字符 ('0'-'9', 'a'-'z')
char val_to_char(int v) {
    if (v >= 0 && v <= 9) {
        return v + '0';
    } else {
        return v - 10 + 'a';
    }
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string c;
    int a, b;
    std::cin >> c >> a >> b;

    // 1. a进制转十进制
    long long decimal_value = 0;
    for (char digit_char : c) {
        decimal_value = decimal_value * a + char_to_val(digit_char);
    }

    // 2. 十进制转b进制
    if (decimal_value == 0) {
        std::cout << "(0)" << b << std::endl;
        return 0;
    }

    std::string result_b = "";
    while (decimal_value > 0) {
        int remainder = decimal_value % b;
        result_b += val_to_char(remainder);
        decimal_value /= b;
    }

    std::reverse(result_b.begin(), result_b.end());

    // 格式化输出
    std::cout << "(" << result_b << ")" << b << std::endl;

    return 0;
}
