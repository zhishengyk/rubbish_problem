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

    // std::lower_bound returns an iterator to the first element
    // that is not less than x (i.e., greater than or equal to x).
    auto it = std::lower_bound(scores.begin(), scores.end(), x);

    if (it != scores.end()) {
        std::cout << *it << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
