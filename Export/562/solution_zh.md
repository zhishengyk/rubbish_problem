## 导游手册查询解法

本题要求我们模拟一个简单的数据库查询过程。我们需要先根据给定的信息（主题和页码）建立一个查询手册，然后对给定的 `M` 个主题，快速查出其对应的页码。

### 核心思路

这个问题的本质是**键值对 (key-value) 映射**的查找。
*   **键 (Key)**: 信息的主题（一个字符串）。
*   **值 (Value)**: 该信息所在的页码（一个整数）。

我们需要一个能够根据“键”快速找到“值”的数据结构。

1.  **暴力方法 (Linear Search)**: 将所有 N 条信息存入一个数组或 `vector`。每次查询时，都从头到尾遍历这个数组，直到找到匹配的主题。单次查询的时间复杂度是 $O(N)$，总复杂度为 $O(N \times M)$，对于 $10^4$ 的数据量会超时。

2.  **排序 + 二分查找 (Sorted Array + Binary Search)**: 将所有信息按主题字符串排序。每次查询时，使用二分查找来定位主题。排序需要 $O(N \log N)$，每次查询需要 $O(\log N)$（但字符串比较会增加成本）。总复杂度约为 $O(N \log N + M \log N)$，是可行的。在C++中，`std::map` 就是基于这种思想（红黑树）实现的。

3.  **哈希表 (Hash Map)**: 这是解决此类问题的最理想、最直接的数据结构。哈希表通过一个哈希函数将键映射到一个桶（bucket），从而实现平均 $O(1)$ 时间复杂度的插入和查找。在C++中，对应的数据结构是 `std::unordered_map`。

### 算法流程 (`std::unordered_map`)

1.  **建立手册**:
    *   声明一个 `std::unordered_map<std::string, int> manual;`。这个 map 将存储从主题（`string`）到页码（`int`）的映射。
    *   读取 `N`，然后循环 `N` 次，每次读取一个主题 `theme` 和一个页码 `page`。
    *   将这对信息存入 map 中: `manual[theme] = page;`。`unordered_map` 的 `[]` 操作符非常方便，如果 `theme` 不存在，它会自动创建新条目；如果已存在，则会更新其值。

2.  **处理查询**:
    *   读取 `M`，然后循环 `M` 次。
    *   每次读取一个要查询的主题 `query_theme`。
    *   直接通过 `manual[query_theme]` 来获取对应的页码，并输出。

这个方法的代码简洁，且效率非常高。

### 代码实现

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void solve() {
    int n;
    std::cin >> n;

    // 使用 unordered_map 来存储主题到页码的映射
    std::unordered_map<std::string, int> manual;
    for (int i = 0; i < n; ++i) {
        std::string theme;
        int page;
        // 题目保证字符串无空格，可以直接用 >> 读取
        std::cin >> theme >> page;
        manual[theme] = page;
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string query_theme;
        std::cin >> query_theme;
        // 直接使用 [] 操作符查找并输出结果
        // 题目保证了查询的主题一定存在
        std::cout << manual[query_theme] << std::endl;
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
*   **时间复杂度**: 建立哈希表需要 $O(N \times L)$，其中 `L` 是字符串的平均长度（计算哈希值和比较所需）。`M` 次查询需要 $O(M \times L)$。总复杂度为 $O((N+M) \times L)$。
*   **空间复杂度**: $O(N \times L)$，用于存储哈希表中的所有键值对。
