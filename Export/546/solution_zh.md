## 约瑟夫问题解法

本题是经典的约瑟夫问题。$n$ 个人围成一圈，每次数到第 $m$ 个人就将其淘汰，然后从下一个人开始继续数。要求输出所有被淘汰的人的编号。

### 核心思路

我们可以用一个数组或 `std::vector` 来模拟这个过程。

1.  **初始化**: 创建一个包含 $1, 2, \dots, n$ 的列表，代表围成一圈的人的编号。
2.  **模拟报数与淘汰**:
    *   我们维持一个当前报数起始位置的指针（或索引）。
    *   从当前位置开始，向后数 $m$ 个人。由于列表是动态缩小的，每次数到的人的索引可以通过取模运算 `(当前位置 + m - 1) % 当前列表长度` 来计算。
    *   找到这个人后，记录下他的编号，然后从列表中删除他。
    *   下一次报数从被删除者的下一个位置开始。
3.  **循环**: 重复这个过程，直到列表为空。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> people(n);
    std::iota(people.begin(), people.end(), 1);

    int current_pos = 0;
    while (!people.empty()) {
        current_pos = (current_pos + m - 1) % people.size();
        std::cout << people[current_pos] << " ";
        people.erase(people.begin() + current_pos);
    }
    std::cout << std::endl;

    return 0;
}
```

### 算法分析

*   **时间复杂度**: 每次淘汰一个人，都需要从 `std::vector` 中删除一个元素。在最坏的情况下，删除操作需要 $O(n)$ 的时间（当删除的元素靠近 вектор 的开头时）。总共有 $n$ 个人要淘汰，所以总时间复杂度是 $O(n^2)$。
*   **空间复杂度**: 我们需要一个额外的 `std::vector` 来存储所有人的编号，所以空间复杂度是 $O(n)$。

考虑到本题的数据范围 $1 \le m, n \le 100$，$O(n^2)$ 的算法是完全可以接受的。
