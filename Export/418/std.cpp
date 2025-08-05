#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 将字符 ('0'-'9', 'A'-'F') 转换为对应的数值 (0-15)
int char_to_val(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return 0;
}

// 将数值 (0-15) 转换为对应的字符 ('0'-'9', 'A'-'F')
char val_to_char(int v) {
    if (v >= 0 && v <= 9) {
        return v + '0';
    } else {
        return v - 10 + 'A';
    }
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::string x;

    std::cin >> n >> x >> m;

    // 1. N进制转十进制
    long long decimal_value = 0;
    for (char c : x) {
        decimal_value = decimal_value * n + char_to_val(c);
    }

    // 2. 十进制转M进制 (除基取余法)
    if (decimal_value == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    std::string result_m = "";
    while (decimal_value > 0) {
        int remainder = decimal_value % m;
        result_m += val_to_char(remainder);
        decimal_value /= m;
    }

    // 结果是反的，需要逆序输出
    std::reverse(result_m.begin(), result_m.end());

    std::cout << result_m << std::endl;

    return 0;
}
