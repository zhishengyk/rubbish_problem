#include <iostream>
#include <vector>
#include <queue>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;
        if (op == 'i') {
            int k;
            std::cin >> k;
            pq.push(k);
        } else { // op == 'q'
            if (!pq.empty()) {
                std::cout << pq.top() << std::endl;
                pq.pop();
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
