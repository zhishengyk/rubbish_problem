#include <iostream>
#include <vector>
#include <algorithm>

bool check(int d, int L, int n, int m, const std::vector<int>& stones) {
    int removed_count = 0;
    int last_pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (stones[i] - last_pos < d) {
            removed_count++;
        } else {
            last_pos = stones[i];
        }
    }
    if (L - last_pos < d) {
        removed_count++;
    }
    return removed_count <= m;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, N, M;
    std::cin >> L >> N >> M;

    std::vector<int> stones(N + 2);
    stones[0] = 0;
    for (int i = 1; i <= N; ++i) {
        std::cin >> stones[i];
    }
    stones[N + 1] = L;
    
    // The check function needs to be adapted to handle the full list including start/end
    auto check_adapted = [&](int d) {
        int removed = 0;
        int current_pos = 0;
        for (int i = 1; i <= N + 1; ++i) {
            if (stones[i] - current_pos < d) {
                removed++;
            } else {
                current_pos = stones[i];
            }
        }
        return removed <= M;
    };

    int left = 1, right = L, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check_adapted(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
