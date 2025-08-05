#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> c[i];
    }

    long long m, p1, s1, s2;
    std::cin >> m >> p1 >> s1 >> s2;

    c[p1] += s1;

    long long dragon_power = 0;
    long long tiger_power = 0;

    for (int i = 1; i < m; ++i) {
        dragon_power += c[i] * (m - i);
    }
    for (int i = m + 1; i <= n; ++i) {
        tiger_power += c[i] * (i - m);
    }

    long long min_diff = std::numeric_limits<long long>::max();
    int best_p2 = -1;

    for (int p2 = 1; p2 <= n; ++p2) {
        long long current_dragon_power = dragon_power;
        long long current_tiger_power = tiger_power;

        if (p2 < m) {
            current_dragon_power += s2 * (m - p2);
        } else if (p2 > m) {
            current_tiger_power += s2 * (p2 - m);
        }

        long long diff = std::abs(current_dragon_power - current_tiger_power);

        if (diff < min_diff) {
            min_diff = diff;
            best_p2 = p2;
        }
    }

    std::cout << best_p2 << std::endl;

    return 0;
}
