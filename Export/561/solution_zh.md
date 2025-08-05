## 第k小价格问题解法

本题的目标是在 `n` 个给定的价格中，找出第 `k` 小的**不重复**价格。

### 核心思路

题目的关键在于两点：一是“去重”，即相同的价格只计算一次；二是“第k小”，即在不重复的价格中找到排序后第 `k` 个。

有几种方法可以解决这个问题：

1.  **排序和去重 (Sort and Unique)**:
    *   将所有 `n` 个价格读入一个 `std::vector`。
    *   对 `vector` 进行排序 (`std::sort`)。
    *   使用 `std::unique` 配合 `vector::erase` 来移除所有重复的元素。
    *   这样，`vector` 中就只剩下排好序的、不重复的价格。
    *   然后直接取第 `k` 个元素（即索引为 `k-1` 的元素）即可。
    *   时间复杂度为 $O(N \log N)$，主要由排序决定。

2.  **使用 `std::set`**:
    *   `std::set` 是一个自动排序且元素唯一的容器。
    *   将所有 `n` 个价格依次插入一个 `std::set`。
    *   插入完成后，`set` 中就是所有不重复且排好序的价格。
    *   然后，我们可以通过迭代器访问第 `k` 个元素。
    *   时间复杂度为 $O(N \log N)$。

3.  **桶排序 / 计数排序思想 (Bucket Sort / Counting Sort)**:
    *   题目给出了一个非常重要的限制：价格都是小于30000的正整数。这个值域范围并不大。
    *   我们可以利用这个特性，避免使用基于比较的、较慢的 $O(N \log N)$ 排序算法。
    *   我们可以创建一个大小为 30000 的布尔数组（或整型数组）作为“桶”，`bool seen[30000]`。
    *   遍历输入的 `n` 个价格，对于每个价格 `p`，我们将 `seen[p]` 标记为 `true`。这一步完成了去重，时间复杂度为 $O(N)$。
    *   然后，我们从 1 到 29999 遍历这个 `seen` 数组。用一个计数器 `count` 记录这是我们遇到的第几个不重复的价格。当 `count` 达到 `k` 时，当前的数组索引 `p` 就是我们要找的第 `k` 小价格。这一步的时间复杂度为 $O(\text{max\_price})$。
    *   总时间复杂度为 $O(N + \text{max\_price})$，对于本题的数据范围来说，这是最高效的方法。

### 算法流程 (桶排序思想)

1.  读取 `n` 和 `k`。
2.  声明一个大小为 30000 的布尔数组 `seen`，并全部初始化为 `false`。
3.  循环 `n` 次，读取每个价格 `p`，并执行 `seen[p] = true;`。
4.  初始化一个计数器 `count = 0`。
5.  从 `p = 1` 开始遍历到 29999：
    *   如果 `seen[p]` 为 `true`，说明 `p` 是一个出现过的价格。
    *   将 `count` 加一。
    *   如果 `count` 等于 `k`，那么 `p` 就是答案。输出 `p` 并结束程序。
6.  如果循环结束后 `count` 仍然小于 `k`，说明不重复的价格总数少于 `k`，按要求输出 "NO RESULT"。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <numeric>

const int MAX_PRICE = 30000;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> seen(MAX_PRICE, false);

    for (int i = 0; i < n; ++i) {
        int price;
        std::cin >> price;
        if (price < MAX_PRICE) { // Bounds check
            seen[price] = true;
        }
    }

    int count = 0;
    for (int p = 1; p < MAX_PRICE; ++p) {
        if (seen[p]) {
            count++;
            if (count == k) {
                std::cout << p << std::endl;
                return; // 找到答案，结束函数
            }
        }
    }

    // 如果循环走完还没返回，说明无解
    std::cout << "NO RESULT" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```
