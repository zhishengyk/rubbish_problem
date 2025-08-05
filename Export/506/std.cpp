#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    std::vector<int> schools(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> schools[i];
    }
    std::sort(schools.begin(), schools.end());

    long long total_dissatisfaction = 0;
    for (int i = 0; i < n; ++i) {
        int student_score;
        std::cin >> student_score;

        auto it = std::lower_bound(schools.begin(), schools.end(), student_score);

        long long min_diff = -1;

        if (it != schools.end()) {
            min_diff = std::abs((long long)*it - student_score);
        }

        if (it != schools.begin()) {
            long long diff2 = std::abs((long long)*(it - 1) - student_score);
            if (min_diff == -1 || diff2 <= min_diff) {
                min_diff = diff2;
            }
        }
        total_dissatisfaction += min_diff;
    }

    std::cout << total_dissatisfaction << std::endl;

    return 0;
}
