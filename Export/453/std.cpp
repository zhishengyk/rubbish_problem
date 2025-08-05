#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 高精度加法
std::string add(std::string a, std::string b) {
    std::string res;
    int carry = 0;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    for (size_t i = 0; i < a.length() || i < b.length() || carry; ++i) {
        int num1 = (i < a.length()) ? a[i] - '0' : 0;
        int num2 = (i < b.length()) ? b[i] - '0' : 0;
        int sum = num1 + num2 + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// 比较两个正整数 represented by string
// a > b -> 1
// a < b -> -1
// a == b -> 0
int compare(const std::string& a, const std::string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}


// 高精度减法
std::string subtract(std::string a, std::string b) {
    int sign = compare(a, b);
    if (sign == 0) return "0";
    if (sign == -1) {
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

    // 去除前导零
    while (res.length() > 1 && res.back() == '0') {
        res.pop_back();
    }
    
    std::reverse(res.begin(), res.end());
    
    if (sign == -1) {
        res.insert(0, "-");
    }

    return res;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b;
    std::cin >> a >> b;

    std::cout << add(a, b) << std::endl;
    std::cout << subtract(a, b) << std::endl;

    return 0;
}
