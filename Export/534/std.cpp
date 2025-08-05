#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

bool is_valid_sequence(const std::vector<int>& seq) {
    std::stack<int> s;
    int current_bullet = 1;
    for (int i = 0; i < seq.size(); ++i) {
        while (s.empty() || s.top() != seq[i]) {
            if (current_bullet > seq.size()) {
                return false;
            }
            s.push(current_bullet);
            current_bullet++;
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

    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> seq(10);
        for (int i = 0; i < 10; ++i) {
            std::cin >> seq[i];
        }
        if (is_valid_sequence(seq)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
