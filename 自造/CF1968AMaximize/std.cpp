#include<bits/stdc++.h>

using namespace std;

// #define int long long
struct Hamel {
    // 基向量数组，每个元素对应二进制位的最高位
    std::vector<int> p;
    // 是否存在零向量（0: 不存在，1: 存在）
    int zero = 1;
    // 非零基向量的数量
    int cnt_h;
    int max_bit = 20;

    Hamel() : zero(0), cnt_h(0) {
        p.resize(max_bit + 1, 0);
    }

    void clear() {
        fill(p.begin(), p.end(), 0);
        zero = 0;
        cnt_h = 0;
    }

    // 通过long long数组构造线性基
    Hamel(const std::vector<long long> &a) : Hamel() {
        for (auto x: a) insert(x);
    }

    // 通过初始化列表构造（例如 Hamel h = {1,2,3};）
    Hamel(std::initializer_list<long long> init) : Hamel() {
        for (auto x: init) insert(x);
    }

    /* 核心操作 */
    // 向线性基中插入元素x
    void insert(long long x) {
        for (int i = max_bit; i >= 0; --i) {
            if ((x >> i) & 1) {          // 检测x的第i位是否为1
                if (p[i]) {
                    x ^= p[i];           // 用已有基向量消去当前位
                } else {
                    p[i] = x;            // 新增基向量
                    ++cnt_h;
                    return;              // 插入成功直接返回
                }
            }
        }
        zero = 1;                        // 能执行到这里说明插入了零向量
    }
    
    // 检查x是否可以被线性基表示
    bool check(long long x) {
        if (x == 0) return true; // An empty set has an XOR sum of 0.
        for (int i = max_bit; i >= 0; --i) {
            if (!p[i]) continue;
            x = min(x, x ^ p[i]);
        }
        return x == 0;
    }

    // 合并另一个线性基（或数组）到当前基
    void merge(const Hamel& other) {
        for (long long x : other.p) {
            if (x) {
                insert(x);
            }
        }
    }
};

Hamel f[19][200005];
int t[19][200005];
vector<int> a;
vector<vector<int>> g;
vector<int> dep;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    t[0][u] = fa;
    // CORRECTED: The basis for a path of length 2^0 (u to parent) only contains the value at u.
    // The parent's value will be included in its own path segment.
    f[0][u].insert(a[u]);

    for (int i = 1; i < 19; i++) {
        int ancestor = t[i - 1][u];
        if (ancestor == 0) continue;
        t[i][u] = t[i - 1][ancestor];
        // The basis for path from u up 2^i ancestors is the merge of
        // basis for u up 2^(i-1) and basis for t[i-1][u] up 2^(i-1)
        f[i][u] = f[i - 1][u];
        f[i][u].merge(f[i - 1][ancestor]);
    }

    for (auto v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

// CORRECTED: Rewritten query function for clarity and correctness.
bool query(int u, int v, int val) {
    Hamel path_basis;
    if (dep[u] < dep[v]) swap(u, v);

    // 1. Lift u to the same depth as v, merging bases along the way.
    int diff = dep[u] - dep[v];
    for (int i = 18; i >= 0; i--) {
        if ((diff >> i) & 1) {
            path_basis.merge(f[i][u]);
            u = t[i][u];
        }
    }

    // If u is the LCA, we are done. u will be equal to v now.
    if (u == v) {
        path_basis.merge(f[0][u]); // Add the LCA's value
        return path_basis.check(val);
    }

    // 2. Lift u and v together to find the LCA.
    for (int i = 18; i >= 0; i--) {
        if (t[i][u] != t[i][v]) {
            path_basis.merge(f[i][u]);
            path_basis.merge(f[i][v]);
            u = t[i][u];
            v = t[i][v];
        }
    }

    // 3. Now u and v are children of the LCA. Add their values and the LCA's value.
    int lca = t[0][u];
    path_basis.merge(f[0][u]); // Add u's value
    path_basis.merge(f[0][v]); // Add v's value
    path_basis.merge(f[0][lca]);// Add LCA's value

    return path_basis.check(val);
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n + 1);
    g.resize(n + 1);
    dep.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        if (query(u, v, x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}