#include <iostream>
#include <vector>
#include <numeric>

const int MAX_PRICE = 30000;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> seen(MAX_PRICE, false);
    int unique_count = 0;

    for (int i = 0; i < n; ++i) {
        int price;
        std::cin >> price;
        if (!seen[price]) {
            seen[price] = true;
        }
    }

    int count = 0;
    for (int p = 1; p < MAX_PRICE; ++p) {
        if (seen[p]) {
            count++;
            if (count == k) {
                std::cout << p << std::endl;
                return;
            }
        }
    }

    // If the loop finishes, it means there are fewer than k unique prices.
    std::cout << "NO RESULT" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
