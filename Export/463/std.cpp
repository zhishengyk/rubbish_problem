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

std::string factorial(int n) {
    if (n == 0) {
        return "1";
    }
    std::string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply_by_int(result, i);
    }
    return result;
}


void solve() {
    int n, a;
    std::cin >> n >> a;

    std::string fact_n = factorial(n);
    char target_digit = a + '0';
    
    int count = 0;
    for (char c : fact_n) {
        if (c == target_digit) {
            count++;
        }
    }
    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
