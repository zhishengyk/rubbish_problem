#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::map<int, int> counts;
    int left = 0;
    int distinct_flowers = 0;
    int min_len = n + 1;
    int best_l = -1, best_r = -1;

    for (int right = 0; right < n; ++right) {
        if (counts[a[right]] == 0) {
            distinct_flowers++;
        }
        counts[a[right]]++;

        while (distinct_flowers == m) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                best_l = left + 1;
                best_r = right + 1;
            } else if (right - left + 1 == min_len) {
                if (left + 1 < best_l) {
                    best_l = left + 1;
                    best_r = right + 1;
                }
            }

            counts[a[left]]--;
            if (counts[a[left]] == 0) {
                distinct_flowers--;
            }
            left++;
        }
    }

    std::cout << best_l << " " << best_r << std::endl;

    return 0;
}
