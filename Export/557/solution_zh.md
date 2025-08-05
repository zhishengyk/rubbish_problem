## 数组区间翻转解法

本题要求对一个数组进行多次指定区间的翻转操作，并输出最终的数组。

### 核心思路

首先，我们需要分析题目的数据范围：$N, M \le 1000$。这个数据量是比较小的，这意味着一个比较直接的、朴素的模拟方法应该是可以通过的，我们不需要设计过于复杂的数据结构。

最直接的方法就是**完全模拟**题目的要求：
1.  用一个 `std::vector` 来存储这个数组。
2.  循环 M 次，每次读取要翻转的区间 `[X, Y]`。
3.  对于每个给定的区间，我们直接调用 C++ 标准库中的 `std::reverse` 函数来对 `std::vector` 的相应子区间进行翻转。

### `std::reverse` 函数的使用

`std::reverse` 函数位于 `<algorithm>` 头文件中，它接受两个迭代器作为参数，`first` 和 `last`，并翻转 `[first, last)` 这个**左闭右开**区间内的元素。

对于一个 `std::vector<int> a` 和 1-indexed 的区间 `[X, Y]`：
*   第 `X` 个元素的迭代器是 `a.begin() + X - 1`。
*   要翻转到第 `Y` 个元素（包含它），那么右开区间的 `last` 迭代器应该是指向第 `Y+1` 个元素的位置，即 `a.begin() + Y`。
*   所以，调用的形式为 `std::reverse(a.begin() + X - 1, a.begin() + Y);`

### 算法流程

1.  读取 N 和 M。
2.  创建一个大小为 N 的 `std::vector` 并读入初始数组。
3.  进入一个循环，执行 M 次：
    *   读取 X 和 Y。
    *   调用 `std::reverse(a.begin() + X - 1, a.begin() + Y);`。
4.  循环结束后，遍历并输出 `std::vector` 中的所有元素。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        // 将 1-based 索引 [x, y] 转换为 0-based 的迭代器范围
        // std::reverse 作用于左闭右开区间 [first, last)
        std::reverse(a.begin() + x - 1, a.begin() + y);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
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
*   **时间复杂度**: `std::reverse` 对一个长度为 `L` 的区间操作，时间复杂度为 $O(L)$。在最坏的情况下，每次翻转的区间长度接近 `N`。总共进行 `M` 次操作，所以总时间复杂度为 $O(M \times N)$。在 $N, M \le 1000$ 的情况下，计算量约为 $1000 \times 1000 = 10^6$，这是完全可以接受的。
*   **空间复杂度**: $O(N)$，用于存储数组。
