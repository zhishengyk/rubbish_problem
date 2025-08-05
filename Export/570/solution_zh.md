## 最小成本照片解法

本题要求我们找到一个包含所有品种奶牛的、连续区间最短的照片。照片的成本定义为该区间内奶牛最大和最小 x 坐标的差。

### 核心思路：滑动窗口

这是一个典型的可以用**滑动窗口 (Sliding Window)** 算法解决的问题。基本思想是维护一个“窗口”，这个窗口代表了我们当前考虑的照片区间。我们尝试扩大和缩小这个窗口，以找到覆盖所有品种奶牛的最短区间。

1.  **排序**: 问题的关键在于 x 坐标的连续区间。因此，我们首先需要将所有的奶牛按照它们的 x 坐标从小到大进行排序。这使得我们可以从左到右线性地处理奶牛。

2.  **滑动窗口**:
    *   我们使用两个指针，`left` 和 `right`，来表示窗口的左右边界。窗口 `[left, right]` 包含所有在排序后数组中下标从 `left` 到 `right` 的奶牛。
    *   我们不断地将 `right` 指针向右移动，这相当于扩大窗口，把新的奶牛加入到照片中。
    *   每当窗口满足“包含所有品种的奶牛”这个条件时，我们就找到了一个“可行解”。此时，这个窗口的成本是 `cows[right].x - cows[left].x`。我们用这个成本更新我们记录的全局最小成本。
    *   在找到一个可行解后，我们不能停下来。因为这个窗口可能不是最优的。我们可以尝试将 `left` 指针向右移动，这相当于缩小窗口，看看是否能在保持窗口有效（仍然包含所有品种）的情况下，得到一个更小的成本。
    *   我们重复这个“扩大-检查-缩小”的过程，直到 `right` 指针到达数组的末尾。

### 状态维护

为了高效地执行上述过程，我们需要快速知道：
1.  总共有多少个不同的品种。
2.  当前窗口内包含了多少个不同的品种。
3.  当前窗口内每个品种的奶牛数量是多少。

我们可以使用以下数据结构来维护这些状态：
*   `std::set<int> breed_ids`: 在读入数据时，用它来统计总共有多少个独一无二的品种。
*   `std::map<int, int> window_counts`: 一个哈希表，用来记录当前窗口内，每个品种ID对应的奶牛数量。
*   `breeds_in_window`: 一个计数器，记录 `window_counts` 中有多少个品种的数量大于0，即窗口内不同品种的总数。

### 算法流程

1.  **初始化**:
    *   读入所有奶牛数据，存入一个 `Cow` 结构体数组中。
    *   使用 `std::set` 确定不同品种的总数 `total_breeds`。
    *   将奶牛数组按 `x` 坐标升序排序。
    *   初始化 `left = 0`, `min_cost = infinity`，以及空的 `window_counts` map 和 `breeds_in_window = 0`。

2.  **滑动窗口**:
    *   用一个 `for` 循环，让 `right` 指针从 `0` 遍历到 `n-1`。
    *   在循环的每一步，将 `cows[right]` 加入窗口：
        *   更新 `window_counts[cows[right].id]++`。
        *   如果这个品种的数量从0变为1，则 `breeds_in_window++`。
    *   **内层循环**: 当窗口变得有效时（即 `breeds_in_window == total_breeds`），执行一个 `while` 循环：
        *   计算当前成本 `cows[right].x - cows[left].x`，并用它来更新 `min_cost`。
        *   尝试缩小窗口：将 `cows[left]` 移出窗口。
        *   更新 `window_counts[cows[left].id]--`。
        *   如果这个品种的数量从1变为0，则 `breeds_in_window--`。
        *   `left++`。
        *   这个 `while` 循环会一直执行，直到窗口不再有效（即因为移除了 `cows[left]` 而缺少了某个品种）。

3.  **结束**:
    *   外层 `for` 循环结束后，`min_cost` 中存储的就是最终答案。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

struct Cow {
    int x, id;
};

bool compareCows(const Cow& a, const Cow& b) {
    return a.x < b.x;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<Cow> cows(n);
    std::set<int> breed_ids;
    for (int i = 0; i < n; ++i) {
        std::cin >> cows[i].x >> cows[i].id;
        breed_ids.insert(cows[i].id);
    }

    int total_breeds = breed_ids.size();
    
    std::sort(cows.begin(), cows.end(), compareCows);

    int min_cost = -1;

    int left = 0;
    std::map<int, int> window_counts;
    int breeds_in_window = 0;

    for (int right = 0; right < n; ++right) {
        // 将右侧奶牛加入窗口
        int right_cow_id = cows[right].id;
        if (window_counts[right_cow_id] == 0) {
            breeds_in_window++;
        }
        window_counts[right_cow_id]++;

        // 当窗口有效时，计算成本并尝试从左侧收缩
        while (breeds_in_window == total_breeds) {
            int current_cost = cows[right].x - cows[left].x;
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }

            // 将左侧奶牛移出窗口
            int left_cow_id = cows[left].id;
            window_counts[left_cow_id]--;
            if (window_counts[left_cow_id] == 0) {
                breeds_in_window--;
            }
            left++;
        }
    }

    std::cout << min_cost << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```
