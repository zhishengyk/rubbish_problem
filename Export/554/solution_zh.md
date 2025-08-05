## 静态区间第K小问题解法

本题是算法竞赛中的一个经典问题：**静态区间第K小**。即，对于一个固定的数组，多次查询某个区间 `[i, j]` 内第 `k` 小的元素是什么。

### 核心思路

暴力做法（对每次查询都排序）的效率太低。解决这个问题的标准高效算法是**可持久化线段树 (Persistent Segment Tree)**，也常被称为**主席树**。

主席树的核心思想是利用线段树来维护**值域**信息，并通过**可持久化**技术来保存历史版本，从而能够高效地查询任意区间的状态。

1.  **离散化 (Discretization)**:
    *   由于原数组中的数值 `a_i` 可能很大（高达 $10^9$），但数量 `N` 在可控范围内（$10^5$），我们不能直接以值为下标建立线段树。
    *   因此，第一步是对所有 `a_i` 进行**离散化**：将所有出现过的数值收集起来，排序并去重，然后用它们在排序后列表中的排名（0-indexed 或 1-indexed）来代替其原始值。这样，值域就被映射到了 `[0, N-1]` 的范围内。

2.  **可持久化线段树的构建**:
    *   我们构建 `N+1` 棵线段树，或者说 `N+1` 个版本的根节点。
    *   `root[i]` 指向的线段树，记录的是原数组**前缀 `A[1...i]`** 中各个数值（的排名）的出现次数。
    *   `root[0]` 是一棵空树，所有节点的计数值都为0。
    *   `root[i]` 是在 `root[i-1]` 的基础上，将 `a[i]` 对应排名的计数值加一而得到的。
    *   **可持久化**体现在：每次更新时，我们不完全复制整棵树，而是只创建被修改路径上的新节点（大约 `log N` 个），而未改变的子树则直接链接到前一个版本的对应子树上。这大大节省了空间和时间。

3.  **查询区间第K小**:
    *   如何查询区间 `A[i...j]` 的信息？我们可以利用前缀和的思想。`root[j]` 维护了 `A[1...j]` 的信息，`root[i-1]` 维护了 `A[1...i-1]` 的信息。那么，`root[j]` 树中对应节点的计数值减去 `root[i-1]` 中对应节点的计数值，就得到了**区间 `A[i...j]`** 中相应值域的数的个数。
    *   查询第 `k` 小的过程，就是在 `root[j]` 和 `root[i-1]` 这两棵树上同时进行二分查找：
        *   从根节点开始，比较两棵树左子树的计数值之差 `count_diff`。这个差值代表了在 `A[i...j]` 中，值落在当前值域左半部分的数的数量。
        *   如果 `k <= count_diff`，说明第 `k` 小的数落在左半边，我们继续在左子树中查找。
        *   否则，说明第 `k` 小的数在右半边，我们到右子树中去查找第 `k - count_diff` 小的数。
    *   这个过程一直持续到叶子节点，此时叶子节点代表的排名就是答案。最后，我们将这个排名映射回离散化之前的原始值。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 100005;

struct Node {
    int l, r;
    int count;
};

Node tree[MAXN * 20]; // 空间需要开大一些
int root[MAXN];
int node_count = 0;
int n, m;
std::vector<int> a;
std::vector<int> discretized;

// 获取离散化后的ID
int get_id(int val) {
    return std::lower_bound(discretized.begin(), discretized.end(), val) - discretized.begin();
}

// 构建空树
void build(int& cur, int l, int r) {
    cur = ++node_count;
    tree[cur].count = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(tree[cur].l, l, mid);
    build(tree[cur].r, mid + 1, r);
}

// 更新，创建新版本
void update(int& cur, int pre, int l, int r, int pos) {
    cur = ++node_count;
    tree[cur] = tree[pre];
    tree[cur].count++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(tree[cur].l, tree[pre].l, l, mid, pos);
    } else {
        update(tree[cur].r, tree[pre].r, mid + 1, r, pos);
    }
}

// 查询
int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int count = tree[tree[v].l].count - tree[tree[u].l].count;
    if (k <= count) {
        return query(tree[u].l, tree[v].l, l, mid, k);
    } else {
        return query(tree[u].r, tree[v].r, mid + 1, r, k - count);
    }
}


void solve() {
    std::cin >> n >> m;
    a.resize(n + 1);
    std::vector<int> temp_for_discrete;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        temp_for_discrete.push_back(a[i]);
    }

    std::sort(temp_for_discrete.begin(), temp_for_discrete.end());
    discretized.erase(std::unique(temp_for_discrete.begin(), temp_for_discrete.end()), temp_for_discrete.end());
    
    int discrete_size = discretized.size();
    build(root[0], 0, discrete_size - 1);

    for (int i = 1; i <= n; ++i) {
        update(root[i], root[i - 1], 0, discrete_size - 1, get_id(a[i]));
    }

    for (int i = 0; i < m; ++i) {
        int l, r, k;
        std::cin >> l >> r >> k;
        int rank = query(root[l - 1], root[r], 0, discrete_size - 1, k);
        std::cout << discretized[rank] << std::endl;
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
*   **时间复杂度**: 离散化 $O(N \log N)$，建树 $O(N \log N)$，每次查询 $O(\log N)$。总复杂度为 $O((N+M)\log N)$。
*   **空间复杂度**: 主席树的空间开销是 $O(N \log N)$。
