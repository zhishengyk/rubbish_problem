## 拥挤的奶牛问题解法

这个问题的目标是计算“拥挤”的奶牛数量。一头奶牛感到拥挤，必须同时满足两个条件：在其左边指定距离 `D` 内，和在其右边指定距离 `D` 内，都存在身高至少是它两倍的奶牛。

### 核心思路

直接对每头奶牛都遍历其他所有奶牛来检查条件，会导致 $O(N^2)$ 的时间复杂度，对于较大的 $N$ 可能会超时。我们可以使用一种更高效的方法。

1.  **排序**: 首先，将所有奶牛按照她们的位置 `x` 从小到大进行排序。这使得我们可以线性地处理奶牛，并方便地确定左右邻近的奶牛。

2.  **两遍扫描 + 滑动窗口最大值**: 我们可以通过两次遍历来分别确定每头奶牛的左边和右边是否存在满足条件的“高个子”奶牛。
    *   **从左到右扫描**: 遍历排序后的奶牛数组。对于当前奶牛 `i`，我们需要知道在 `[x_i - D, x_i)` 这个区间内奶牛的最大身高。这可以通过“滑动窗口最大值”算法来高效实现。我们用一个双端队列（`deque`）来维护一个单调递减的身高序列。这样，队首元素始终是当前窗口内的最大身高。
        *   我们维护一个左指针 `l_ptr`，确保窗口内的奶牛与当前奶牛 `i` 的距离不超过 `D`。
        *   在将奶牛 `i` 加入窗口前，我们检查当前窗口的最大身高（即队首元素）是否至少是奶牛 `i`身高的两倍。如果是，我们就记录下奶牛 `i` 的左边有一个高个子邻居。
        *   然后，我们将奶牛 `i` 的身高加入窗口，并保持窗口的单调性。
    *   **从右到左扫描**: 同理，我们从右向左再遍历一次奶牛数组，用同样的方法来判断每头奶牛的右边是否存在高个子邻居。

3.  **统计结果**: 创建两个布尔数组 `has_tall_left` 和 `has_tall_right`。在上述两次扫描中记录结果。最后，遍历这两个数组，统计 `has_tall_left[i]` 和 `has_tall_right[i]` 同时为 `true` 的奶牛数量。

由于奶牛排序后，原始的索引被打乱，我们需要在 `Cow` 结构体中保存其原始 `id`，以便在布尔数组中正确地更新它们的状态。

### 代码实现
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

struct Cow {
    int id;
    int x, h;
};

bool compareCows(const Cow& a, const Cow& b) {
    return a.x < b.x;
}

void solve() {
    int n;
    long long d;
    std::cin >> n >> d;
    std::vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        cows[i].id = i;
        std::cin >> cows[i].x >> cows[i].h;
    }

    std::sort(cows.begin(), cows.end(), compareCows);

    std::vector<bool> has_tall_left(n, false);
    std::deque<std::pair<int, int>> max_h_window_left; // {height, index_in_cows}
    int l_ptr = 0;
    for (int i = 0; i < n; ++i) {
        while (l_ptr < i && cows[i].x - cows[l_ptr].x > d) {
            if (!max_h_window_left.empty() && max_h_window_left.front().second == l_ptr) {
                max_h_window_left.pop_front();
            }
            l_ptr++;
        }
        if (!max_h_window_left.empty() && max_h_window_left.front().first >= 2 * cows[i].h) {
            has_tall_left[cows[i].id] = true;
        }
        while (!max_h_window_left.empty() && max_h_window_left.back().first <= cows[i].h) {
            max_h_window_left.pop_back();
        }
        max_h_window_left.push_back({cows[i].h, i});
    }

    std::vector<bool> has_tall_right(n, false);
    std::deque<std::pair<int, int>> max_h_window_right; // {height, index_in_cows}
    int r_ptr = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (r_ptr > i && cows[r_ptr].x - cows[i].x > d) {
            if (!max_h_window_right.empty() && max_h_window_right.front().second == r_ptr) {
                max_h_window_right.pop_front();
            }
            r_ptr--;
        }
        if (!max_h_window_right.empty() && max_h_window_right.front().first >= 2 * cows[i].h) {
            has_tall_right[cows[i].id] = true;
        }
        while (!max_h_window_right.empty() && max_h_window_right.back().first <= cows[i].h) {
            max_h_window_right.pop_back();
        }
        max_h_window_right.push_back({cows[i].h, i});
    }

    int crowded_cows = 0;
    for (int i = 0; i < n; ++i) {
        if (has_tall_left[i] && has_tall_right[i]) {
            crowded_cows++;
        }
    }

    std::cout << crowded_cows << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析
*   **时间复杂度**: 排序需要 $O(N \log N)$。两次扫描处理每个奶牛的时间是均摊 $O(1)$，所以两次扫描总共是 $O(N)$。因此，总的时间复杂度为 $O(N \log N)$。
*   **空间复杂度**: 需要 $O(N)$ 的空间来存储奶牛、布尔数组以及双端队列。
