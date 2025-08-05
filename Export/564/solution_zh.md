## 统计数字出现次数解法

本题是一个基础的数据处理问题，要求我们完成两件事：
1.  **统计频率**：计算输入的一组数中，每个不同的数字出现了多少次。
2.  **排序输出**：将结果按照数字从小到大的顺序输出。

### 核心思路

我们需要一个数据结构，既能存储数字（作为键），又能存储其对应的出现次数（作为值）。同时，这个数据结构最好能自动地按照键（也就是数字本身）进行排序，以满足输出要求。

**`std::map`** 是解决这个问题的完美工具。

*   **`std::map` 简介**:
    *   `std::map` 是 C++ 标准库中的关联容器，它存储的是**键值对 (key-value pairs)**。
    *   它的一个核心特性是，`map` 中的元素会根据键自动进行排序。对于整数键，默认就是从小到大排序。
    *   这恰好同时满足了我们统计频率和排序输出的两大需求。

### 算法流程

1.  **声明一个 `map`**:
    *   我们声明一个 `std::map<int, int> counts;`。
    *   `int` 类型的键（`key`）将用来存储输入的数字。
    *   `int` 类型的值（`value`）将用来存储该数字出现的次数。

2.  **读取输入并计数**:
    *   读取整数 `n`。
    *   循环 `n` 次，每次从输入中读取一个数字 `num`。
    *   执行 `counts[num]++;`。
    *   `map` 的 `[]` 操作符非常方便：
        *   如果 `num` 这个键在 `map` 中还不存在，`map` 会自动创建一个新的键值对，键为 `num`，值为默认的0，然后 `++` 操作将其变为1。
        *   如果 `num` 这个键已经存在，`[]` 操作会返回其对应的值的引用，`++` 操作会直接将其计数值加一。

3.  **输出结果**:
    *   当所有 `n` 个数字都读完并处理后，`counts` 这个 `map` 中就已经存储了所有不重复的数字及其出现次数，并且是按数字大小排好序的。
    *   我们只需要遍历这个 `map`，并依次输出每个键值对即可。
    ```cpp
    for (const auto& pair : counts) {
        // pair.first 是键（数字）
        // pair.second 是值（次数）
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    ```

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    // 使用 map 来存储数字及其出现次数
    // map 会自动根据键（数字）进行排序
    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        counts[num]++;
    }

    // 遍历 map 并输出结果
    // map 中的元素已经是按键排好序的
    for (const auto& pair : counts) {
        std::cout << pair.first << " " << pair.second << std::endl;
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
*   **时间复杂度**: 向 `map` 中插入/更新一个元素的时间复杂度是 $O(\log K)$，其中 `K` 是 `map` 中不同元素的数量。我们执行 `n` 次这样的操作，所以总的时间复杂度是 $O(n \log K)$（其中 $K \le n$）。
*   **空间复杂度**: `map` 需要存储所有不重复的数字及其计数，所以空间复杂度是 $O(K)$。
对于本题 $n \le 1000$ 的数据规模，这个算法效率非常高。
