#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    std::stack<int> s;
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && h[s.top()] > h[i]) {
            s.pop();
        }
        if (!s.empty() && h[s.top()] < h[i]) {
            max_len = std::max(max_len, i - s.top() + 1);
        }
        s.push(i);
    }

    std::cout << max_len << std::endl;

    return 0;
}
