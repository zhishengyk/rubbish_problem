#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }

    // std::upper_bound returns an iterator to the first element
    // that is greater than x.
    auto it = std::upper_bound(scores.begin(), scores.end(), x);

    if (it == scores.begin()) {
        // All elements are greater than x.
        std::cout << -1 << std::endl;
    } else {
        // The element before it is the last one <= x.
        std::cout << *std::prev(it) << std::endl;
    }

    return 0;
}
