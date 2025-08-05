## 最大不互斥子集问题解法

本题要求我们从一个包含N个不同正整数的集合中，找出一个最大的子集，使得子集中的任意两个元素 `x` 和 `y` 都不满足 `y = P*x` 的关系。

### 核心思路：图论建模

我们可以将这个问题转化为一个图论问题。
*   **顶点 (Vertices)**: 集合中的每一个数都是图中的一个顶点。
*   **边 (Edges)**: 如果两个数 `x` 和 `y` 满足互斥关系（即 `y = P*x` 或 `x = P*y`），我们就在它们对应的顶点之间连一条边。

这样一来，原问题就变成了：在这个构造出的图上，找到一个**最大独立集 (Maximum Independent Set)**。最大独立集指的是，在一个图中选取尽可能多的顶点，使得这些顶点两两之间没有边相连。

### 图的结构与解耦

我们观察这个图的结构。边只在 `x` 和 `P*x` 这种形式的数之间存在。这意味着，图是由若干条不相交的“链”组成的。每一条链都具有 `c, c*P, c*P^2, c*P^3, ...` 的形式（其中所有这些数都存在于原集合中）。

例如，当 `P=2`，输入集合为 `{1, 2, 3, 4, 6, 8, 12}` 时，图会分解成两条独立的链：
*   链1: `1 -- 2 -- 4 -- 8`
*   链2: `3 -- 6 -- 12`

因为这些链是互不相连的，我们可以独立地计算每一条链的最大独立集，然后将结果相加，就得到了整个图的最大独立集。

### 链上的最大独立集

现在问题简化为：如何求一条长度为 `k` 的路径图 `v_1 -- v_2 -- ... -- v_k` 的最大独立集？
这是一个简单的动态规划问题。选了 `v_i` 就不能选 `v_{i-1}` 和 `v_{i+1}`。不难发现，为了选出最多的点，我们应该交替地选择，例如 `v_1, v_3, v_5, ...`。
对于一条长度为 `k` 的链，其最大独立集的顶点数是 `ceil(k/2)`，用整数除法可以方便地计算为 `(k + 1) / 2`。

### 算法流程

1.  **排序**: 首先，对输入的 `N` 个数进行升序排序。这使得我们可以方便地识别和构建每一条链。
2.  **标记与遍历**: 使用一个哈希集合（`std::unordered_set`）`visited` 来记录哪些数已经被分配到某个链中。我们从头到尾遍历排序后的数组 `a`。
3.  **寻找链的起点**: 对于数组中的每个数 `a[i]`，如果它还没有被访问过（即不在 `visited` 中），那么它一定是一条新链的起点（因为如果 `a[i]/P` 存在，它一定在 `a[i]` 前面，并且在处理 `a[i]/P` 时已经把 `a[i]` 加入了链并标记为已访问）。
4.  **构建链并计算**:
    *   从这个起点 `current_num = a[i]` 开始，计算这条链的长度 `chain_length`。
    *   不断地将 `current_num` 乘以 `P`，并检查新的 `current_num` 是否存在于原数组中（可以使用二分查找 `std::binary_search`）。
    *   只要存在，就将 `chain_length` 加一，并将这个新数标记为已访问。
    *   当链构建完毕后，根据公式 `(chain_length + 1) / 2` 计算这条链的最大独立集大小，并累加到总答案 `total_max_subset_size` 中。
5.  **输出**: 遍历完所有数后，输出 `total_max_subset_size`。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

void solve() {
    int n;
    long long p;
    // 题目描述是多组数据，但样例只有一组。按多组数据处理更稳妥。
    while (std::cin >> n >> p) {
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        std::unordered_set<long long> visited;
        int total_max_subset_size = 0;

        for (int i = 0; i < n; ++i) {
            if (visited.count(a[i])) {
                continue;
            }

            // 因为数组已排序，任何未访问过的数都是一条新链的起点
            int chain_length = 0;
            long long current_num = a[i];

            // 检查这条链有多长
            while (std::binary_search(a.begin(), a.end(), current_num)) {
                visited.insert(current_num);
                chain_length++;
                
                // 检查乘法是否会溢出
                if (__builtin_mul_overflow(current_num, p, &current_num)) {
                    break; // 溢出后肯定不在集合内，链结束
                }
            }
            // 计算这条链的最大独立集并累加
            total_max_subset_size += (chain_length + 1) / 2;
        }
        std::cout << total_max_subset_size << std::endl;
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
*   **时间复杂度**: 排序需要 $O(N \log N)$。之后遍历数组，对于每个数字，我们可能会进行一次二分查找（`binary_search`）和哈希表操作（`insert`），这两者都很快。二分查找是 $O(\log N)$。因此，总复杂度由排序和后续的循环主导，约为 $O(N \log N)$。
*   **空间复杂度**: $O(N)$，主要用于存储输入的数和 `visited` 集合。
