#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        // Adjust for 0-based indexing.
        // The range [x, y] corresponds to iterators a.begin() + x - 1
        // and a.begin() + y.
        std::reverse(a.begin() + x - 1, a.begin() + y);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
