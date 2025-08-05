#include <iostream>
#include <stack>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::stack<int> s;
    std::stack<int> max_s;

    for (int i = 0; i < n; ++i) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int x;
            std::cin >> x;
            s.push(x);
            if (max_s.empty() || x >= max_s.top()) {
                max_s.push(x);
            }
        } else if (op == 1) {
            if (!s.empty()) {
                if (s.top() == max_s.top()) {
                    max_s.pop();
                }
                s.pop();
            }
        } else if (op == 2) {
            if (max_s.empty()) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << max_s.top() << std::endl;
            }
        }
    }

    return 0;
}
