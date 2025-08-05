#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

// 将36进制字符 ('0'-'9', 'A'-'Z') 转换为对应的数值 (0-35)
long long char_to_val_36(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else { // 'A' to 'Z'
        return c - 'A' + 10;
    }
}

// 将36进制字符串转换为十进制
long long base36_to_dec(const std::string& str36) {
    long long dec_val = 0;
    for (char c : str36) {
        dec_val = dec_val * 36 + char_to_val_36(c);
    }
    return dec_val;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<long long> dec_values;
    std::string license_plate;

    while (std::cin >> license_plate) {
        // 提取后5位进行转换
        std::string payload = license_plate.substr(2, 5);
        dec_values.push_back(base36_to_dec(payload));
    }

    if (dec_values.size() < 2) {
        // 如果不足两个牌照，无法计算差值
        std::cout << 0 << std::endl; 
        return 0;
    }

    // 排序
    std::sort(dec_values.begin(), dec_values.end());

    // 查找最小差值
    long long min_diff = LLONG_MAX;
    for (size_t i = 1; i < dec_values.size(); ++i) {
        long long diff = dec_values[i] - dec_values[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    std::cout << min_diff << std::endl;

    return 0;
}
