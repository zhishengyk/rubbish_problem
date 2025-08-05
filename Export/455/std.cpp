#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 高精度加法
std::string add(std::string a, std::string b) {
    if (a == "0") return b;
    if (b == "0") return a;
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

// 高精度乘低精度 (int)
std::string multiply_by_int(std::string a, int b) {
    if (a == "0" || b == 0) return "0";
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string total_sum = "0";
    std::string current_factorial = "1";

    for (int i = 1; i <= n; ++i) {
        // 更新阶乘到 i!
        current_factorial = multiply_by_int(current_factorial, i);
        
        // 计算项 (n-i+1) * i!
        std::string term = multiply_by_int(current_factorial, n - i + 1);
        
        // 累加到总和
        total_sum = add(total_sum, term);
    }

    std::cout << total_sum << std::endl;

    return 0;
}
