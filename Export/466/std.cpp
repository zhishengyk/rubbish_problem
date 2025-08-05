#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

// 预处理质数
std::vector<int> primes;
void generate_primes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

std::vector<int> parse_number(const std::string& s) {
    std::vector<int> res;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, ',')) {
        res.push_back(std::stoi(item));
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 预处理足够多的质数
    generate_primes(5000); // 假设位数不会太多

    std::string line;
    std::cin >> line;

    size_t plus_pos = line.find('+');
    std::string s_num1 = line.substr(0, plus_pos);
    std::string s_num2 = line.substr(plus_pos + 1);

    std::vector<int> num1 = parse_number(s_num1);
    std::vector<int> num2 = parse_number(s_num2);

    std::vector<int> result;
    int carry = 0;
    size_t max_len = std::max(num1.size(), num2.size());

    for (size_t i = 0; i < max_len || carry; ++i) {
        int d1 = (i < num1.size()) ? num1[i] : 0;
        int d2 = (i < num2.size()) ? num2[i] : 0;
        
        int base = primes[i];
        int sum = d1 + d2 + carry;
        
        result.push_back(sum % base);
        carry = sum / base;
    }
    
    std::reverse(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : ",");
    }
    std::cout << std::endl;

    return 0;
}
