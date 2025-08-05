#include <iostream>
#include <vector>
#include <map>

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}

long long nCr_mod_p(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    
    std::vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % 1000000007;
    }
    
    return (((fact[n] * modInverse(fact[r])) % 1000000007) * modInverse(fact[n - r])) % 1000000007;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int len;
        std::cin >> len;
        counts[len]++;
    }

    long long total_ways = 0;
    long long mod = 1e9 + 7;

    for (auto const& [len, count] : counts) {
        if (count >= 3) {
            long long C3 = 1;
            if (count >= 3) C3 = (long long)count * (count - 1) * (count - 2) / 6;
            total_ways = (total_ways + C3 * (n - count)) % mod;
        }
        if (count >= 4) {
            long long C4 = (long long)count * (count - 1) * (count - 2) * (count - 3) / 24;
            total_ways = (total_ways + C4) % mod;
        }
    }

    std::cout << total_ways << std::endl;

    return 0;
}
