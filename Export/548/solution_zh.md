## 取牌游戏解法

这是一个模拟题，我们需要精确地模拟发牌的全过程，并记录下小明（玩家1）获得的牌的原始位置。

### 核心思路

我们可以使用一个数据结构来模拟牌堆。由于需要在牌堆的顶部取牌，并在底部放牌，`std::list` 或 `std::queue` 是理想的选择。这里我们选用 `std::list`，因为它在头部和尾部的插入/删除操作都是 $O(1)$ 的。

1.  **初始化**:
    *   创建一个 `std::list`，按顺序存储从 1 到 K 的所有牌的编号。
    *   确定玩家的顺序。小明是1号，发牌从他右手边的人（2号）开始，逆时针方向，即 2, 3, ..., N, 1, 2, ...。我们可以用一个变量 `current_player` 来追踪当前该给谁发牌。初始时 `current_player = 2`。
    *   创建一个 `std::vector` 用于存储小明获得的牌的编号。

2.  **模拟发牌过程**:
    *   进行一个循环，总共发 K 张牌。
    *   在循环的每一步：
        1.  **判断发给谁**: 检查当前的 `current_player` 是否是小明（即1号）。如果是，将牌堆顶部的牌的编号（`deck.front()`）存入小明的牌的向量中。
        2.  **发牌**: 从牌堆顶部移除一张牌 (`deck.pop_front()`)。
        3.  **移动牌**: 如果牌堆不为空，将接下来的 P 张牌从顶部移动到底部。这可以通过一个循环实现：`deck.push_back(deck.front()); deck.pop_front();` 重复 P 次。
        4.  **更新玩家**: 将 `current_player` 指向下一个玩家。`current_player++`。如果 `current_player` 超过了 N，就让他变回 1，形成一个循环。

3.  **输出结果**:
    *   当所有 K 张牌都发完后，对小明获得的牌的编号列表进行升序排序。
    *   按要求格式输出排序后的编号。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

void solve() {
    int n, k, p;
    std::cin >> n >> k >> p;

    std::list<int> deck;
    for (int i = 1; i <= k; ++i) {
        deck.push_back(i);
    }

    std::vector<int> xiaoming_cards;
    int current_player = 2;

    for (int i = 0; i < k; ++i) {
        if (current_player == 1) {
            xiaoming_cards.push_back(deck.front());
        }
        deck.pop_front();

        if (deck.empty()) break;

        for (int j = 0; j < p; ++j) {
            deck.push_back(deck.front());
            deck.pop_front();
        }

        current_player++;
        if (current_player > n) {
            current_player = 1;
        }
    }

    std::sort(xiaoming_cards.begin(), xiaoming_cards.end());

    for (size_t i = 0; i < xiaoming_cards.size(); ++i) {
        std::cout << xiaoming_cards[i] << std::endl;
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

*   **时间复杂度**: 外层循环执行 K 次。在每次循环中，移动 P 张牌需要 $O(P)$ 的时间。所以模拟过程的时间复杂度是 $O(K \times P)$。最后排序需要 $O(M \log M)$ 的时间，其中 M 是小明拿到的牌数 (M = K/N)。总的时间复杂度为 $O(K \times P + (K/N) \log (K/N))$。
*   **空间复杂度**: 我们需要一个 `std::list` 存储 K 张牌，以及一个 `std::vector` 存储小明的牌。所以空间复杂度是 $O(K)$。
考虑到 K 的最大值为 100000，P 最大为 10，这个复杂度是可以接受的。
