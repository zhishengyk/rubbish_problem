## 论坛回复查询解法

本题要求我们模拟一个论坛系统，支持两种核心操作：给指定帖子增加一条回复，以及查询指定帖子的第y条回复是什么。

### 核心思路

这个问题本质上是要求我们为每个帖子ID维护一个动态的、有序的列表。
*   `ADD x y` 操作是在ID为 `x` 的帖子的列表末尾追加一个新元素 `y`。
*   `QUERY x y` 操作是查询ID为 `x` 的帖子的列表中第 `y` 个元素。

我们需要一个数据结构，能够将帖子ID `x` 映射到它对应的回复列表。由于帖子ID是从1到100000的整数，我们可以直接使用一个**数组或 `std::vector` 作为主容器**，数组的索引就代表帖子ID。

对于每个帖子ID所对应的“回复列表”，我们需要一个能够高效地在末尾添加元素，并能通过索引快速访问元素的数据结构。**`std::vector`** 是这个场景下的完美选择。

### 数据结构设计

我们可以声明一个“二维”的 `std::vector`：
```cpp
std::vector<std::vector<int>> posts(100001);
```
*   `posts` 是一个 `vector`，它的大小我们设置为 100001，这样就可以用 `posts[x]` 来直接访问帖子 `x` 的数据。
*   `posts[x]` 本身也是一个 `std::vector<int>`，它用来存储帖子 `x` 的所有回复者的ID。由于回复是按时间顺序发生的，我们每次 `ADD` 操作 просто在 `vector` 的末尾添加即可。

### 算法流程

1.  **初始化**:
    *   `std::vector<std::vector<int>> posts(100001);`

2.  **处理操作**:
    *   循环N次，每次读取一行操作。
    *   读取操作类型（"ADD" 或 "QUERY"）、帖子ID `x` 和 另一个整数 `y`。
    *   **如果是 "ADD"**:
        *   这表示用户 `y` 回复了帖子 `x`。我们将 `y` 添加到帖子 `x` 的回复列表中。
        *   `posts[x].push_back(y);`
    *   **如果是 "QUERY"**:
        *   这表示查询帖子 `x` 的第 `y` 条回复。
        *   首先，我们需要检查帖子 `x` 是否有至少 `y` 条回复。回复总数是 `posts[x].size()`。
        *   如果 `y > posts[x].size()`，则查询无效，按要求输出 -1。
        *   否则，第 `y` 条回复在 `vector` 中的索引是 `y - 1`（因为 `vector` 是0-indexed）。我们输出 `posts[x][y - 1]`。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <string>

// 将 posts 声明为全局变量或在 main 中创建并传递
std::vector<std::vector<int>> posts(100001);

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string op;
        int x, y;
        std::cin >> op >> x >> y;

        if (op == "ADD") {
            posts[x].push_back(y);
        } else if (op == "QUERY") {
            // 查询第 y 个回复，对应 vector 的 y-1 索引
            if (y > posts[x].size()) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << posts[x][y - 1] << std::endl;
            }
        }
    }
}

int main() {
    // 加速 C++ IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    solve();
    
    return 0;
}
```

### 算法分析
*   **时间复杂度**:
    *   `posts[x].push_back(y)`: `std::vector` 的 `push_back` 操作是均摊 $O(1)$ 的。
    *   `posts[x][y-1]`: `std::vector` 的索引访问是 $O(1)$ 的。
    *   总共有 `N` 次操作，所以总时间复杂度为 $O(N)$。
*   **空间复杂度**: 最坏情况下，所有操作都是 `ADD`，需要存储 `N` 个回复。主 `vector` 大小固定。总空间复杂度为 $O(\text{MaxPostID} + N)$，在本题中约为 $O(100001 + 100000)$。
