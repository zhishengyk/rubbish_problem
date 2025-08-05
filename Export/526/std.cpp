#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Pair {
    long long l;
    long long r;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.l < b.l;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m;
    std::cin >> m;

    std::vector<Pair> solutions;
    long long two_m = 2 * m;

    for (long long n = 2; n * n < two_m; ++n) {
        // From l = (2M - n^2 + n) / (2n)
        long long numerator = two_m - n * n + n;
        long long denominator = 2 * n;

        if (numerator > 0 && numerator % denominator == 0) {
            long long l = numerator / denominator;
            long long r = l + n - 1;
            solutions.push_back({l, r});
        }
    }

    std::sort(solutions.begin(), solutions.end(), comparePairs);

    for (const auto& p : solutions) {
        std::cout << p.l << " " << p.r << std::endl;
    }

    return 0;
}
