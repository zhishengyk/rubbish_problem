#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 200005;
const int MAX_VAL = 1000005;

struct Query {
    int id, l, r;
};

int n, q;
int a[MAXN];
int bit[MAXN];
int last_pos[MAX_VAL];
long long ans[MAXN];
std::vector<Query> queries;

void add(int pos, int val) {
    for (; pos <= n; pos += pos & -pos) {
        bit[pos] += val;
    }
}

int query(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos & -pos) {
        sum += bit[pos];
    }
    return sum;
}

bool compareQueries(const Query& a, const Query& b) {
    return a.r < b.r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        queries.push_back({i, 0, 0});
        std::cin >> queries[i].l >> queries[i].r;
    }

    std::sort(queries.begin(), queries.end(), compareQueries);

    int query_idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (last_pos[a[i]] != 0) {
            add(last_pos[a[i]], -1);
        }
        add(i, 1);
        last_pos[a[i]] = i;

        while (query_idx < q && queries[query_idx].r == i) {
            ans[queries[query_idx].id] = query(queries[query_idx].r) - query(queries[query_idx].l - 1);
            query_idx++;
        }
    }

    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
