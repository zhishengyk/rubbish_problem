#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

bool is_valid_sequence(int n, const std::vector<int>& seq) {
    std::stack<int> s;
    int current_train = 1;
    for (int i = 0; i < n; ++i) {
        while (s.empty() || s.top() != seq[i]) {
            if (current_train > n) {
                return false;
            }
            s.push(current_train);
            current_train++;
        }
        if (s.top() == seq[i]) {
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }

    if (is_valid_sequence(n, seq)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
