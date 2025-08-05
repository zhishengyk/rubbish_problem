#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long L, R;
    std::cin >> n >> L >> R;
    std::vector<long long> T(n), M(n), t(n), m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> T[i] >> M[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i] >> m[i];
    }

    for (int i = 0; i < n; ++i) {
        long long problem_idx = i + 1;
        if (problem_idx >= L && problem_idx <= R) {
            std::cout << "System Error\n";
        } else {
            if (M[i] > m[i]) {
                std::cout << "Memory Limit Exceeded\n";
            } else if ((T[i] / 2) > t[i]) {
                std::cout << "Time Limit Exceeded\n";
            } else {
                std::cout << "Accepted\n";
            }
        }
    }

    return 0;
}
