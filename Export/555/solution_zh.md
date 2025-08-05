## 动态序列维护问题解法

本题要求我们维护一个数字序列，并支持在任意位置插入和删除元素。这是一个经典的动态序列问题。

### 核心思路

使用普通数组或 `std::vector` 来实现，每次插入或删除操作都可能需要移动大量元素，时间复杂度为 $O(N)$，对于 $10^5$ 的数据量来说太慢了。同样，使用 `std::list` 虽然插入删除本身快，但定位到第 X 个元素需要 $O(X)$ 的时间，总体效率也不高。

解决这类问题的标准方法有平衡二叉搜索树（如Splay或Treap）或者更复杂的树套树结构。但这些数据结构实现起来非常复杂。一个实现相对简单且性能足够通过本题的算法是**分块 (Block Decomposition)**，也叫**块状链表**。

分块的基本思想是“大段维护，局部朴素”。我们将整个序列分成若干个块（block），每块的大小为一个合适的常数 `B`（通常取 $\sqrt{N}$）。

1.  **数据结构**:
    *   我们可以用 `std::vector<std::list<int>> blocks` 来存储。外层 `vector` 的每个元素是一个 `list`，这个 `list` 就是一个块。使用 `list` 的好处是块内插入删除快，`vector` 也可以，但内部移动开销大些。

2.  **操作实现**:
    *   **定位第 X 个元素**: 我们需要遍历所有块，用一个计数器 `current_pos` 记录当前已经过的元素总数。当 `current_pos + 当前块的大小 >= X` 时，我们就知道第 X 个元素在这个块内。然后在这个块内再遍历 `X - current_pos` 步即可找到目标。这个过程最多遍历 $\sqrt{N}$ 个块，块内最多遍历 $\sqrt{N}$ 个元素，总复杂度为 $O(\sqrt{N})$。
    *   **插入操作 (在第X个元素后插入Y)**: 先用 $O(\sqrt{N})$ 的时间定位到第 X 个元素所在的块和具体位置。然后执行插入。
    *   **删除操作 (删除第X个元素)**: 同样，先用 $O(\sqrt{N})$ 的时间定位，然后执行删除。

3.  **块的维护 (Rebuild)**:
    *   当频繁进行插入和删除后，有的块可能变得很大，有的可能变得很小，这会影响性能。为了维持效率，我们需要定期**重构 (rebuild)** 所有块。
    *   一个简单的策略是：当某个块的大小超过 `2 * B` 时，我们就把所有块中的所有元素拿出来，重新平均分配到新的块中。
    *   重构操作虽然耗时 $O(N)$，但由于它不经常发生，所以均摊到每次操作上的成本是可以接受的。

这种方法将每次操作的时间复杂度从 $O(N)$ 成功地优化到了 $O(\sqrt{N})$，足以应对本题的数据规模。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <numeric>

const int BLOCK_SIZE = 320; // Approximately sqrt(100000)

std::vector<std::list<int>> blocks;

void rebuild() {
    std::vector<int> all_elements;
    for (const auto& block : blocks) {
        all_elements.insert(all_elements.end(), block.begin(), block.end());
    }
    blocks.clear();
    for (size_t i = 0; i < all_elements.size(); ++i) {
        if (i % BLOCK_SIZE == 0) {
            blocks.push_back({});
        }
        blocks.back().push_back(all_elements[i]);
    }
    if (blocks.empty()) {
        blocks.push_back({});
    }
}

void insert_val(int x, int y) {
    if (x == 0) {
        blocks.front().push_front(y);
        if (blocks.front().size() > 2 * BLOCK_SIZE) rebuild();
        return;
    }

    int current_pos = 0;
    for (auto& block : blocks) {
        if (current_pos + block.size() >= x) {
            int inner_idx = x - current_pos -1;
            auto it = block.begin();
            std::advance(it, inner_idx);
            it++; // after the x-th element
            block.insert(it, y);
            if (block.size() > 2 * BLOCK_SIZE) rebuild();
            return;
        }
        current_pos += block.size();
    }
}

void delete_val(int x) {
    int current_pos = 0;
    for (auto& block : blocks) {
        if (current_pos + block.size() >= x) {
            int inner_idx = x - current_pos - 1;
            auto it = block.begin();
            std::advance(it, inner_idx);
            block.erase(it);
            // A simple periodic rebuild triggered by insertion is often enough
            return;
        }
        current_pos += block.size();
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i % BLOCK_SIZE == 0) {
            blocks.push_back({});
        }
        blocks.back().push_back(a[i]);
    }
     if (blocks.empty()) {
        blocks.push_back({});
    }

    for (int k = 0; k < m; ++k) {
        int opt, x, y;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> x >> y;
            insert_val(x, y);
        } else {
            std::cin >> x;
            delete_val(x);
        }
    }

    bool first = true;
    for (const auto& block : blocks) {
        for (int val : block) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << val;
            first = false;
        }
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
*   **时间复杂度**: 每次操作都需要 $O(\sqrt{N})$ 的时间，重构需要 $O(N)$ 但发生次数少。总复杂度约为 $O(M\sqrt{N})$。
*   **空间复杂度**: $O(N)$。
