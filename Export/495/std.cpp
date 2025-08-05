#include <iostream>
#include <vector>

const int MAX_M = 1000001;
std::vector<bool> is_prime(MAX_M, true);
std::vector<int> prime_count(MAX_M, 0);

void sieve(int m) {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= m; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= m; i += p)
                is_prime[i] = false;
        }
    }

    for (int i = 1; i <= m; ++i) {
        prime_count[i] = prime_count[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    sieve(m);

    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        if (l < 1 || r > m || l > r) {
            std::cout << "Crossing the line" << std::endl;
        } else {
            std::cout << prime_count[r] - prime_count[l - 1] << std::endl;
        }
    }

    return 0;
}
