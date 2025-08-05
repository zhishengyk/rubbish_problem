#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief 判断一个数是否是质数
 * @param n 要判断的数
 * @return 如果是质数返回true，否则返回false
 */
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

/**
 * @brief 判断一个数是否是回文数
 * @param n 要判断的数
 * @return 如果是回文数返回true，否则返回false
 */
bool is_palindrome(int n) {
    std::string s = std::to_string(n);
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b;
    std::cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (is_palindrome(i) && is_prime(i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
