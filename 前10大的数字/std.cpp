#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    std::multiset<long long> top10; // 升序存储，保持最多 10 个元素

    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        top10.insert(x);
        if (top10.size() > 10) top10.erase(top10.begin()); // 删除最小值，留下最大的 10 个

        // 按降序输出当前集合
        bool first = true;
        for (auto it = top10.rbegin(); it != top10.rend(); ++it) {
            if (!first) cout << ' ';
            cout << *it;
            first = false;
        }
        cout << '\n';
    }
    return 0;
} 