#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int MAXN = 100005;

struct Node {
    int l, r;
    int count;
};

Node tree[MAXN * 20];
int root[MAXN];
int node_count = 0;
int n, m;
std::vector<int> a;
std::vector<int> discretized;

int get_id(int val) {
    return std::lower_bound(discretized.begin(), discretized.end(), val) - discretized.begin();
}

void build(int& cur, int l, int r) {
    cur = ++node_count;
    tree[cur].count = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(tree[cur].l, l, mid);
    build(tree[cur].r, mid + 1, r);
}

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
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        discretized.push_back(a[i]);
    }

    std::sort(discretized.begin(), discretized.end());
    discretized.erase(std::unique(discretized.begin(), discretized.end()), discretized.end());
    
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
