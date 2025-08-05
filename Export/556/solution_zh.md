## 最多能选的钻石解法

这个问题要求我们从一组给定的钻石（具有不同的大小）中选出一个子集，使得子集中最大钻石和最小钻石的大小差不超过 `K`，并最大化这个子集的大小。

### 核心思路

直接在未排序的钻石中寻找最优子集会非常复杂。这个问题的关键突破口在于**排序**。

1.  **排序**:
    *   首先，我们将所有钻石的大小进行升序排序。
    *   排序后，任何一个有效的子集（即满足 `max - min <= K`）都必然对应于排序后数组的一个**连续子数组**。
    *   为什么呢？假设我们选择了一个满足条件的子集，其最小和最大钻石在排序后的数组中分别是 `s_i` 和 `s_j` (`i < j`)。那么，对于任何在它们之间的钻石 `s_k` (`i < k < j`)，一定满足 `s_i <= s_k <= s_j`。这意味着，将 `s_k` 加入子集，并不会破坏 `max - min <= K` 的条件。因此，我们可以把 `s_i` 和 `s_j` 之间的所有钻石都选上，以获得最大的数量。
    *   所以，问题就转化为了：在排序后的数组中，找到一个最长的连续子数组，使得其最后一个元素与第一个元素之差不大于 `K`。

2.  **双指针 (Two Pointers) / 滑动窗口 (Sliding Window)**:
    *   这是一个非常适合用双指针解决的典型问题。我们使用两个指针 `left` 和 `right` 来维护一个“窗口”。
    *   初始化 `left = 0`, `right = 0`。
    *   `right` 指针不断向右移动，以扩大窗口。
    *   在每一步，我们检查窗口的有效性，即 `sorted_s[right] - sorted_s[left] <= K`。
    *   如果窗口变得无效（差值大于 `K`），我们就需要将 `left` 指针向右移动，以缩小窗口，直到窗口重新变得有效。
    *   在 `right` 的每次移动后，当前由 `[left, right]` 界定的窗口都是一个有效的候选。我们计算其长度 `right - left + 1`，并用它来更新我们记录的最大长度 `max_diamonds`。
    *   重复此过程，直到 `right` 指针遍历完整个数组。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    std::sort(s.begin(), s.end());

    int max_diamonds = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        // 当窗口无效时，收缩左边界
        while (s[right] - s[left] > k) {
            left++;
        }
        // 当前窗口 [left, right] 是有效的，更新最大值
        max_diamonds = std::max(max_diamonds, right - left + 1);
    }

    std::cout << max_diamonds << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析
*   **时间复杂度**: 排序需要 $O(N \log N)$。双指针扫描的过程，`left` 和 `right` 指针都只从头到尾移动一次，所以扫描部分是 $O(N)$。总的时间复杂度由排序主导，为 $O(N \log N)$。
*   **空间复杂度**: $O(N)$ 用于存储钻石大小的数组（如果允许在原地排序，则可以认为是 $O(1)$，不计输入存储）。
