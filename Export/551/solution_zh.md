## 最少删去列数问题解法

这个问题的目标是，通过删除最少的列，使得表格的三行分别排序后内容完全相同。这等价于**最大化保留的列数**。

### 核心思路

让我们将三行分别表示为 `R1`, `R2`, `R3`。一个关键信息是 `R1` 是 `1` 到 `N` 的一个排列。

如果我们保留一个列的集合，那么这些列中的数字在三行中必须构成相同的多重集（multiset）。因为 `R1` 在保留的列中没有重复数字，所以 `R2` 和 `R3` 在这些列中的数字也必须是 `R1` 中数字的一个排列。

这个问题可以转化为一个关于图论和置换的问题：

1.  **构建函数图 (Functional Graphs)**:
    *   首先，我们可以重新组织数据。对于 `R1` 中的每一个数字 `v`（从 1 到 N），我们可以找到它所在的列索引。然后，我们可以建立两个映射关系：
        *   `b_map[v]`: 在 `R1` 中值为 `v` 的那一列，`R2` 的值是多少。
        *   `c_map[v]`: 在 `R1` 中值为 `v` 的那一列，`R3` 的值是多少。
    *   这样，我们就有了两个从 `{1, ..., N}` 到自身的函数（或称之为图，每个节点只有一个出度）。

2.  **置换和循环 (Permutations and Cycles)**:
    *   如果我们决定保留一组列，其在 `R1` 中对应的数字集合为 `S`，那么 `b_map` 和 `c_map` 在 `S` 上的限制必须都是 `S` 的一个置换。
    *   一个函数在集合 `S` 上是置换，当且仅当其函数图在 `S` 上的部分是由若干个不相交的、覆盖 `S` 中所有节点的循环组成的。
    *   因此，一个数字 `v` 能被保留，它必须同时位于 `b_map` 图的一个循环中，和 `c_map` 图的一个循环中。不是循环一部分的节点（即处于“链”上的节点）最终会指向一个循环或者没有后继，它们不能构成置换，所以必须被删除。

3.  **寻找可保留的组件 (Finding Keepable Components)**:
    *   **步骤一：过滤**。我们首先分别找出 `b_map` 和 `c_map` 函数图中的所有循环。一个节点只有同时在这两种图的循环里，才有可能被保留。我们可以用 DFS 找到所有属于循环的节点，然后取其交集，得到 `relevant_nodes`。
    *   **步骤二：合并**。如果我们保留一个节点 `v`，我们必须保留 `b_map` 中与 `v` 在同一个循环的所有节点，也必须保留 `c_map` 中与 `v` 在同一个循环的所有节点。这个约束具有传递性。例如，如果 `v` 和 `u` 在同一个B-循环，`u` 和 `w` 在同一个C-循环，那么保留 `v` 就意味着必须保留 `u` 和 `w`。
    *   我们可以把这种关系建成一个新的图，其中 `relevant_nodes` 是节点。如果两个节点在同一个B-循环或C-循环中，我们就在它们之间连一条边。我们要找的是这个新图的连通分量。使用**并查集 (DSU)** 是解决这个问题的经典方法。
    *   **步骤三：验证**。遍历 `relevant_nodes`，对于每个节点 `v`，我们将 `v` 和 `b_map[v]` 合并，也将 `v` 和 `c_map[v]` 合并。这样，所有必须被一起保留的节点就会被分到同一个集合中。
    *   最后，我们检查每个通过DSU找到的组件。一个组件 `C` 是有效的（可以被完整保留），当且仅当对于其中任意一个节点 `v`，`b_map[v]` 和 `c_map[v]` 都仍然在组件 `C` 内。如果一个组件不满足这个“闭包”性质，那么它就不能被保留。

4.  **计算结果**:
    *   将所有有效的、可保留的组件的大小相加，得到 `kept_count`。
    *   最终答案就是 `N - kept_count`。

### 代码实现
```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>

// DSU data structure
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(3, std::vector<int>(n));
    std::vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[0][i];
        pos[a[0][i]] = i;
    }
    for (int i = 0; i < n; ++i) std::cin >> a[1][i];
    for (int i = 0; i < n; ++i) std::cin >> a[2][i];

    std::vector<int> b_map(n + 1), c_map(n + 1);
    for (int i = 1; i <= n; ++i) {
        b_map[i] = a[1][pos[i]];
        c_map[i] = a[2][pos[i]];
    }

    auto get_cycle_nodes = [&](const std::vector<int>& graph) {
        std::set<int> cycle_nodes;
        std::vector<int> visited(n + 1, 0); // 0: unvisited, 1: visiting, 2: visited
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 0) {
                std::vector<int> path;
                int curr = i;
                while (visited[curr] == 0) {
                    visited[curr] = 1;
                    path.push_back(curr);
                    curr = graph[curr];
                }

                if (visited[curr] == 1) { // Cycle detected
                    bool in_cycle = false;
                    for (int node : path) {
                        if (node == curr) in_cycle = true;
                        if (in_cycle) {
                            cycle_nodes.insert(node);
                        }
                    }
                }
                for(int node : path) {
                    visited[node] = 2;
                }
            }
        }
        return cycle_nodes;
    };

    std::set<int> b_cycle_nodes = get_cycle_nodes(b_map);
    std::set<int> c_cycle_nodes = get_cycle_nodes(c_map);

    std::set<int> relevant_nodes;
    std::set_intersection(b_cycle_nodes.begin(), b_cycle_nodes.end(),
                          c_cycle_nodes.begin(), c_cycle_nodes.end(),
                          std::inserter(relevant_nodes, relevant_nodes.begin()));

    DSU dsu(n);
    for (int node : relevant_nodes) {
        dsu.unite(node, b_map[node]);
        dsu.unite(node, c_map[node]);
    }
    
    std::map<int, std::set<int>> components;
    for (int node : relevant_nodes) {
        components[dsu.find(node)].insert(node);
    }

    int kept_count = 0;
    for (auto const& [root, component_nodes] : components) {
        bool ok = true;
        for (int node : component_nodes) {
            if (component_nodes.find(b_map[node]) == component_nodes.end() ||
                component_nodes.find(c_map[node]) == component_nodes.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            kept_count += component_nodes.size();
        }
    }

    std::cout << n - kept_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析
*   **时间复杂度**: 构建映射关系是 $O(N)$。寻找循环节点是两次DFS，为 $O(N)$。并查集操作接近 $O(N \alpha(N))$，其中 $\alpha$ 是反阿克曼函数，基本可视为常数。最后验证组件也是 $O(N)$。总时间复杂度为 $O(N)$。
*   **空间复杂度**: 需要 $O(N)$ 空间存储映射、图、并查集等数据结构。
