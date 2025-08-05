## 会话列表模拟解法

本题要求我们模拟一个即时聊天软件的会话列表的更新逻辑。这个逻辑是一种经典的“移至最前 (Move-to-Front)”或“最近最常使用 (Most Recently Used, MRU)”策略。

其规则可以统一为：**当一个会话 `id` 活跃时，将它置于列表的最顶端**。
*   如果该 `id` 原本就在列表中，则先从原位置删除，再插入到最顶端。
*   如果该 `id` 原本不在列表中，则直接在最顶端插入。

### 核心思路

我们需要一个能够高效地在任意位置删除元素、并在头部插入元素的数据结构。考虑到题目给定的数据规模非常小（每个测试用例最多 `N=200` 次操作），一个简单的直接模拟就足够了，不需要特别高级的数据结构。

`std::list` 是 C++ 标准库中的双向链表，它非常适合这个场景。
*   在任意位置删除元素，只要有迭代器，就是 $O(1)$。
*   在头部插入元素（`push_front`）是 $O(1)$。
*   查找一个元素需要 $O(N)$。

综合起来，处理一次信息（查找、删除、插入）的总时间是 $O(N)$。对于一个有 `N` 次操作的测试用例，总时间复杂度是 $O(N^2)$。当 $N=200$ 时，$N^2 = 40000$，这个计算量非常小，完全可以接受。

### 算法流程 (使用 `std::list`)

我们可以将“存在则移动，不存在则插入”这两个分支逻辑合并成一个更简洁的操作：**“先删除，再插入”**。

对于每一个到来的会话 `id`：
1.  **尝试删除**: 调用 `session_list.remove(id);`。这个函数会查找 `session_list` 中所有值为 `id` 的元素并删除它们。因为我们的列表中id是唯一的，所以这最多只会删除一个元素。如果 `id` 原本就不在列表中，这个操作不产生任何效果。
2.  **插入到头部**: 调用 `session_list.push_front(id);`。这将 `id` 添加到列表的最前方。

这个“先删后插”的组合拳完美地实现了题目的要求。

**完整流程**:
1.  对于每组测试数据：
2.  创建一个空的 `std::list<int> session_list`。
3.  读取操作次数 `N`。
4.  循环 `N` 次，每次读取一个会话 `id`。
5.  执行 `session_list.remove(id);`。
6.  执行 `session_list.push_front(id);`。
7.  `N` 次操作结束后，遍历 `session_list` 并按格式要求输出所有 `id`。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void solve_case() {
    int n;
    std::cin >> n;
    
    std::list<int> session_list;

    for (int i = 0; i < n; ++i) {
        int id;
        std::cin >> id;
        
        // 步骤1: 尝试从列表中删除 id（如果存在）
        session_list.remove(id);
        
        // 步骤2: 将 id 插入到列表的最前方
        session_list.push_front(id);
    }

    // 输出最终的会话列表
    bool first = true;
    for (int id : session_list) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << id;
        first = false;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t; // 读取测试数据组数
    while (t--) {
        solve_case();
    }
    
    return 0;
}
```
