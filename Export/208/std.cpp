#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }

    if (n <= m) {
        // 如果人数不多于龙头数，总时间取决于接水最多的人
        int max_w = 0;
        for (int val : w) {
            if (val > max_w) {
                max_w = val;
            }
        }
        std::cout << max_w << std::endl;
        return 0;
    }

    // tap_finish_times[j] 表示第 j 个水龙头何时会空闲
    std::vector<long long> tap_finish_times(m, 0);

    // 前 m 个人先接水
    for (int i = 0; i < m; ++i) {
        tap_finish_times[i] = w[i];
    }

    // 从第 m+1 个人开始，分配到最早空闲的水龙头
    for (int i = m; i < n; ++i) {
        // 找到最早空闲的水龙头
        auto min_it = std::min_element(tap_finish_times.begin(), tap_finish_times.end());
        
        // 将当前的人分配到这个水龙头
        // 新的完成时间 = 该龙头原来的完成时间 + 这个人的接水时间
        *min_it += w[i];
    }

    // 总时间取决于最晚结束的那个水龙头
    long long total_time = 0;
    for (long long time : tap_finish_times) {
        if (time > total_time) {
            total_time = time;
        }
    }

    std::cout << total_time << std::endl;

    return 0;
}
