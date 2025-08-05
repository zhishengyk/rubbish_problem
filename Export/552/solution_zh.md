## 滑动窗口最值问题解法

本题是一个经典的算法问题：**滑动窗口最大值/最小值**。我们需要在一个大小为 `k` 的窗口在数组上从左到右滑动时，实时计算出窗口内的最大值和最小值。

### 核心思路

如果对每个窗口都遍历一次来寻找最值，时间复杂度将是 $O(N \times K)$，在 $N$ 和 $K$ 较大时会超时。一个高效的解决方案是使用**双端队列 (deque)**，它可以在 $O(N)$ 的时间内解决此问题。

我们以求解滑动窗口最大值为例来讲解算法（最小值同理）。

1.  **数据结构**: 我们使用一个 `deque`，但它里面存储的不是元素值，而是元素在原数组中的**索引**。这个 `deque` 将始终保持一个特殊的性质：其存储的索引所对应的数组值是**单调递减**的。
    *   这样一来，`deque` 的队首（`front`）索引所对应的，永远是当前窗口内的最大值。

2.  **算法流程**:
    *   我们遍历数组中的每个元素 `a[i]`（从 `i = 0` 到 `n-1`）：
        1.  **移除窗口外的元素**：在处理新元素 `i` 之前，先检查队首的索引 `dq.front()`。如果这个索引已经超出了当前窗口的范围（即 `dq.front() <= i - k`），就将其从队首弹出 `dq.pop_front()`。
        2.  **维护队列的单调性**：从队尾开始，向前检查。如果队尾的索引所对应的元素 `a[dq.back()]` 小于或等于当前元素 `a[i]`，说明它不可能成为后续窗口的最大值（因为 `a[i]` 更大且更“新”）。因此，将这个队尾索引弹出 `dq.pop_back()`。重复此过程，直到队列为空，或者队尾元素大于 `a[i]`。
        3.  **加入新元素**: 将当前元素的索引 `i` 加入队尾 `dq.push_back()`。
        4.  **记录结果**: 当 `i >= k - 1` 时，说明窗口已经形成。此时，队首的索引 `dq.front()` 就对应着当前窗口的最大值。我们将 `a[dq.front()]` 存入结果数组。

3.  **求解最小值**:
    *   求解最小值的过程完全一样，只需一个独立的 `deque`。唯一的区别是在第2步维护单调性时，我们将队列维持成一个索引对应值**单调递增**的序列。即，当队尾元素**大于或等于**当前元素时，将其弹出。

通过这种方法，每个元素的索引最多只入队和出队一次，因此总的时间复杂度是线性的 $O(N)$。

### 代码实现
```cpp
#include <iostream>
#include <vector>
#include <deque>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> min_results;
    std::vector<int> max_results;
    std::deque<int> min_dq;
    std::deque<int> max_dq;

    for (int i = 0; i < n; ++i) {
        // Remove elements outside the window
        if (!min_dq.empty() && min_dq.front() <= i - k) {
            min_dq.pop_front();
        }
        if (!max_dq.empty() && max_dq.front() <= i - k) {
            max_dq.pop_front();
        }

        // Maintain monotonic properties
        while (!min_dq.empty() && a[min_dq.back()] >= a[i]) {
            min_dq.pop_back();
        }
        while (!max_dq.empty() && a[max_dq.back()] <= a[i]) {
            max_dq.pop_back();
        }

        // Add current element
        min_dq.push_back(i);
        max_dq.push_back(i);

        // Store results
        if (i >= k - 1) {
            min_results.push_back(a[min_dq.front()]);
            max_results.push_back(a[max_dq.front()]);
        }
    }

    for (size_t i = 0; i < min_results.size(); ++i) {
        std::cout << min_results[i] << (i == min_results.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    for (size_t i = 0; i < max_results.size(); ++i) {
        std::cout << max_results[i] << (i == max_results.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析
*   **时间复杂度**: $O(N)$，因为每个元素最多入队和出队一次。
*   **空间复杂度**: $O(K)$，因为在最坏的情况下，双端队列中可能存储 `k` 个索引。
