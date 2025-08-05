#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::vector<long long> nums;
    std::vector<char> ops;

    long long current_num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            current_num = (current_num * 10 + (c - '0')) % 10000;
        } else {
            nums.push_back(current_num);
            current_num = 0;
            ops.push_back(c);
        }
    }
    nums.push_back(current_num);

    std::vector<long long> addition_terms;
    long long term = nums[0];

    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '*') {
            term = (term * nums[i + 1]) % 10000;
        } else {
            addition_terms.push_back(term);
            term = nums[i + 1];
        }
    }
    addition_terms.push_back(term);

    long long result = 0;
    for (long long t : addition_terms) {
        result = (result + t) % 10000;
    }

    std::cout << result << std::endl;

    return 0;
}
