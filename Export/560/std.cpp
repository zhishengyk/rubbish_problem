#include <iostream>
#include <vector>
#include <string>

// Use a global or pass it around. Global is fine for this problem size.
std::vector<std::vector<int>> posts(100001);

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string op;
        int x, y;
        std::cin >> op >> x >> y;

        if (op == "ADD") {
            posts[x].push_back(y);
        } else if (op == "QUERY") {
            // y is 1-indexed, vector is 0-indexed
            if (y > posts[x].size()) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << posts[x][y - 1] << std::endl;
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
