#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool is_greater(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a > b;
}

std::string subtract(std::string a, std::string b) {
    bool negative = false;
    if (!is_greater(a, b)) {
        std::swap(a, b);
        negative = true;
    }

    std::string result = "";
    int n1 = a.length(), n2 = b.length();
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((a[i] - '0') - (b[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = ((a[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    std::reverse(result.begin(), result.end());
    
    // 移除前导零
    size_t first_digit = result.find_first_not_of('0');
    if (std::string::npos != first_digit) {
        result = result.substr(first_digit);
    } else {
        result = "0";
    }

    if (negative && result != "0") {
        result = "-" + result;
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string a, b;
    std::cin >> a >> b;
    std::cout << subtract(a, b) << std::endl;
    return 0;
}
