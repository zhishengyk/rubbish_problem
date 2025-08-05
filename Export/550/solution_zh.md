## 排队问题解法

本题是一个模拟题，核心在于高效地处理在一个序列中间的插入和删除操作。

### 核心思路

题目的操作主要有两种：
1.  **在指定元素旁边插入新元素**：编号为 `i` 的同学需要被插入到已在队列中的 `k` 号同学的左边或右边。
2.  **从队列中删除指定元素**。

对于这种需要在序列中间进行频繁插入和删除的操作，使用数组或 `std::vector` 会非常低效，因为每次操作都可能需要移动大量元素，导致时间复杂度为 $O(N)$。

一个理想的数据结构是**双向链表**，在C++中对应的是 `std::list`。双向链表允许在任意位置进行 $O(1)$ 时间的插入和删除，只要我们有指向该位置的迭代器。

为了能够快速定位到任何一个同学在链表中的位置，我们可以额外使用一个辅助的数据结构：一个**存储迭代器的数组**（或 `std::vector`）。

### 具体实现步骤

1.  **数据结构选择**:
    *   `std::list<int> queue`: 用于存储同学们的队列。
    *   `std::vector<std::list<int>::iterator> positions`: 一个大小为 `N+1` 的向量，`positions[i]` 存储了指向 `i` 号同学在 `queue` 中节点的迭代器。
    *   `std::vector<bool> in_queue`: 一个大小为 `N+1` 的布尔向量，用于标记一个同学当前是否在队列中，方便处理删除操作。

2.  **构建初始队列**:
    *   从1号同学开始，将他加入 `queue`。
    *   将 `queue.begin()`（即指向1号同学的迭代器）存入 `positions[1]`。
    *   对于 $i=2, \dots, N$:
        *   读入 `k` 和 `p`。
        *   通过 `positions[k]` 直接获取 `k` 号同学的迭代器。
        *   如果 `p=0` (左边)，使用 `queue.insert(positions[k], i)` 将 `i` 插入到 `k` 的左边。
        *   如果 `p=1` (右边)，使用 `queue.insert(std::next(positions[k]), i)` 将 `i` 插入到 `k` 的右边。（`std::next` 获取下一个位置的迭代器）。
        *   `insert` 函数会返回一个指向新插入元素的迭代器，务必用它来更新 `positions[i]`。
        *   同时设置 `in_queue[i] = true`。

3.  **处理删除操作**:
    *   读入要删除的同学数量 `M`。
    *   循环 `M` 次，每次读入要删除的同学编号 `x`。
    *   检查 `in_queue[x]`。如果为 `true`，说明该同学还在队列中：
        *   使用 `queue.erase(positions[x])` 从链表中删除该同学。这是一个 $O(1)$ 的操作。
        *   更新 `in_queue[x] = false`，防止重复删除。

4.  **输出结果**:
    *   遍历最终的 `queue`，并按顺序输出所有同学的编号。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

void solve() {
    int n;
    std::cin >> n;

    std::list<int> queue;
    std::vector<std::list<int>::iterator> positions(n + 1);
    std::vector<bool> in_queue(n + 1, false);

    // 1号同学入列
    queue.push_back(1);
    positions[1] = queue.begin();
    in_queue[1] = true;

    // 2~N号同学入列
    for (int i = 2; i <= n; ++i) {
        int k, p;
        std::cin >> k >> p;
        if (p == 0) { // 左边
            positions[i] = queue.insert(positions[k], i);
        } else { // 右边
            positions[i] = queue.insert(std::next(positions[k]), i);
        }
        in_queue[i] = true;
    }

    // 去掉M个同学
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        if (in_queue[x]) {
            queue.erase(positions[x]);
            in_queue[x] = false;
        }
    }

    // 输出队列
    bool first = true;
    for (int student : queue) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << student;
        first = false;
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
*   **时间复杂度**: 构建队列时，每次插入都是 $O(1)$，总共是 $O(N)$。删除同学时，每次查找和删除都是 $O(1)$，总共是 $O(M)$。因此，总时间复杂度为 $O(N+M)$。
*   **空间复杂度**: 需要 $O(N)$ 的空间来存储链表、迭代器向量和布尔向量。
