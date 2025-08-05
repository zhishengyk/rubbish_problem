## 吃草问题解法

这个问题要求我们维护一个集合，并支持两种操作：
1.  向集合中添加一个数。
2.  从集合中找出并删除最小的数。

这两种操作是**优先队列 (Priority Queue)** 数据结构的经典应用场景。

### 核心思路

优先队列是一种特殊的队列，它允许我们高效地插入元素，并随时提取出队列中的最小（或最大）元素。

*   **对于操作 'i k'**: 这对应优先队列的“入队” (push) 操作。
*   **对于操作 'q'**: 这对应优先队列的“查看队首” (top) 和“出队” (pop) 操作。

在C++中，我们可以使用 `std::priority_queue`。默认情况下，它是一个**大根堆 (max-heap)**，即 `top()` 操作返回的是最大值。为了满足题目“吃掉数量最少”的要求，我们需要一个**小根堆 (min-heap)**。

我们可以通过向 `std::priority_queue` 提供额外的模板参数来将其配置为小根堆：
`std::priority_queue<int, std::vector<int>, std::greater<int>> pq;`

### 算法流程

1.  创建一个小根堆 `pq`。
2.  循环 `n` 次，读取每个操作。
3.  如果操作是 `'i k'`，则将 `k` 压入优先队列：`pq.push(k);`
4.  如果操作是 `'q'`，则：
    *   首先检查队列是否为空 (`!pq.empty()`)，以避免程序错误。
    *   输出队首元素，即最小值：`std::cout << pq.top() << std::endl;`
    *   将队首元素从队列中移除：`pq.pop();`

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>

void solve() {
    int n;
    std::cin >> n;
    // 声明一个小根堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;
        if (op == 'i') {
            int k;
            std::cin >> k;
            pq.push(k);
        } else { // op == 'q'
            if (!pq.empty()) {
                std::cout << pq.top() << std::endl;
                pq.pop();
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析
*   **时间复杂度**: 优先队列的 `push` 和 `pop` 操作的时间复杂度都是 $O(\log M)$，其中 $M$ 是队列中当前的元素数量。`top` 操作是 $O(1)$。总共有 $N$ 次操作，所以总时间复杂度为 $O(N \log N)$。
*   **空间复杂度**: 在最坏的情况下，所有操作都是插入操作，优先队列需要存储 $N$ 个元素，因此空间复杂度为 $O(N)$。
