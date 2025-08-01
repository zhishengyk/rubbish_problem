#include <iostream>
#include <vector>
#include <numeric>

const int MAX_R = 1000000;
long long factor_sum[MAX_R + 1];
int abundant_prefix_sum[MAX_R + 1];

void sieve() {
    for (int i = 1; i <= MAX_R; ++i) {
        for (int j = i; j <= MAX_R; j += i) {
            factor_sum[j] += i;
        }
    }
}

void precompute_abundant() {
    sieve();
    abundant_prefix_sum[0] = 0;
    for (int i = 1; i <= MAX_R; ++i) {
        abundant_prefix_sum[i] = abundant_prefix_sum[i - 1];
        if (factor_sum[i] >= 2LL * i) {
            abundant_prefix_sum[i]++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    precompute_abundant();
    int n;
    std::cin >> n;
    while (n--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << abundant_prefix_sum[r] - abundant_prefix_sum[l - 1] << "\n";
    }
    return 0;
}
