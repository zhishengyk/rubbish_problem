#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q, p;
    std::cin >> n >> q >> p;

    std::vector<long long> a(n + 1, 0);
    std::vector<long long> diff(n + 2, 0);

    std::cin >> a[1];
    diff[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        std::cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int l, r, x;
        std::cin >> l >> r >> x;
        diff[l] += x;
        if (r + 1 <= n) {
            diff[r + 1] -= x;
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + diff[i];
    }

    for (int i = 0; i < p; ++i) {
        int num;
        std::cin >> num;
        std::cout << a[num] << std::endl;
    }

    return 0;
}
