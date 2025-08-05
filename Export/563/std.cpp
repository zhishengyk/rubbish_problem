#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<int> tails;
    tails.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        if (a[i] > tails.back()) {
            tails.push_back(a[i]);
        } else {
            // Find the first element in tails that is not less than a[i]
            // and replace it.
            *std::lower_bound(tails.begin(), tails.end(), a[i]) = a[i];
        }
    }

    std::cout << tails.size() << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
