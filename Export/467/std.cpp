#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

char to_char(int d) {
    if (d >= 0 && d <= 9) {
        return d + '0';
    }
    return d - 10 + 'A';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_in;
    int neg_base;
    std::cin >> n_in >> neg_base;

    int n = n_in; // Use a copy for calculation
    int r_base = -neg_base;
    std::string result;

    if (n == 0) {
        result = "0";
    } else {
        while (n != 0) {
            int remainder = n % neg_base;
            n /= neg_base;
            
            if (remainder < 0) {
                remainder += r_base; // remainder -= neg_base
                n++;
            }
            result.push_back(to_char(remainder));
        }
    }
    
    std::reverse(result.begin(), result.end());
    
    std::cout << n_in << "=" << result << "(base" << neg_base << ")" << std::endl;

    return 0;
}
