#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string n_str;
    int s;
    std::cin >> n_str >> s;

    std::string result; // Use string as a stack
    
    for (char digit : n_str) {
        while (!result.empty() && s > 0 && result.back() > digit) {
            result.pop_back();
            s--;
        }
        result.push_back(digit);
    }

    // If s > 0, it means the remaining digits are in increasing order.
    // We should remove the largest ones from the end.
    while (s > 0 && !result.empty()) {
        result.pop_back();
        s--;
    }

    // Handle leading zeros
    size_t first_digit_pos = result.find_first_not_of('0');
    if (std::string::npos != first_digit_pos) {
        std::cout << result.substr(first_digit_pos) << std::endl;
    } else {
        // Handle case where result is empty or all zeros
        std::cout << "0" << std::endl;
    }

    return 0;
}
