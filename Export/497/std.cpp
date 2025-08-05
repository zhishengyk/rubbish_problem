#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> diff(n + 2, 0);

    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    int flip_count = 0;
    for (int i = 1; i <= n; ++i) {
        flip_count += diff[i];
        std::cout << (flip_count % 2);
    }
    std::cout << std::endl;

    return 0;
}
