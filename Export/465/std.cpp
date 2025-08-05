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

// 高精度减 1
std::string subtract_one(std::string a) {
    if (a == "1") return "0";
    
    int n = a.length();
    int i = n - 1;

    while (i >= 0 && a[i] == '0') {
        a[i] = '9';
        i--;
    }
    
    if (i >= 0) {
        a[i]--;
    }

    // 去除可能的前导零
    size_t first_digit_pos = 0;
    if (a.length() > 1 && a[0] == '0') {
        first_digit_pos = a.find_first_not_of('0');
        if (std::string::npos != first_digit_pos) {
            return a.substr(first_digit_pos);
        }
    }
    
    return a;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 计算 2^n
    std::string power_of_2 = "1";
    for (int i = 0; i < n; ++i) {
        power_of_2 = multiply_by_int(power_of_2, 2);
    }
    
    // 减去 1
    std::string result = subtract_one(power_of_2);

    std::cout << result << std::endl;

    return 0;
}
