#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string solve() {
    std::string n;
    int k;
    std::cin >> n >> k;

    std::vector<char> s;
    for (char c : n) {
        while (!s.empty() && s.back() > c && k > 0) {
            s.pop_back();
            k--;
        }
        s.push_back(c);
    }

    while (k > 0) {
        s.pop_back();
        k--;
    }

    std::string result = "";
    bool leading_zero = true;
    for (char c : s) {
        if (leading_zero && c == '0') {
            continue;
        }
        leading_zero = false;
        result += c;
    }

    if (result.empty()) {
        return "0";
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::cout << solve() << std::endl;
    }
    return 0;
}
