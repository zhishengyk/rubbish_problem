#include <iostream>
#include <vector>
#include <stack>

bool is_valid_pop_sequence(const std::vector<int>& pushed, const std::vector<int>& popped) {
    std::stack<int> s;
    int j = 0;
    for (int i = 0; i < pushed.size(); ++i) {
        s.push(pushed[i]);
        while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
            s.pop();
            j++;
        }
    }
    return j == popped.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;
        std::vector<int> pushed(n), popped(n);
        for (int i = 0; i < n; ++i) std::cin >> pushed[i];
        for (int i = 0; i < n; ++i) std::cin >> popped[i];

        if (is_valid_pop_sequence(pushed, popped)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
