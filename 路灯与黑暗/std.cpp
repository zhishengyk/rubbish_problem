#include <bits/stdc++.h>
using namespace std;

/*
 * 经典解法：
 *   pos  : set<long long>      —— 维护所有路灯坐标（含 0 和 L），有序便于找到左右相邻路灯。
 *   gap  : multiset<long long> —— 维护相邻两盏路灯之间的间距；取 *rbegin() 即可得最大黑暗区间长度。
 * 
 * 核心思想：
 *   1. 插入/删除一个坐标 x，只会影响它左右两盏路灯之间的那一段（或两段）。
 *   2. 每次操作只对 gap 中常数级元素做增删，复杂度 O(log n)。
 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L; int m;
    if(!(cin >> L >> m)) return 0;

    set<long long> pos{0, L};      // 所有路灯位置，升序
    multiset<long long> gap{L};    // 相邻路灯间距，初始只有 [0,L]

    string op;
    while(m--){
        cin >> op;
        if(op == "add"){
            long long x; cin >> x;
            if(!pos.insert(x).second) continue;        // 已存在忽略
            auto it = pos.find(x);                     // 指向 x
            long long r = *next(it);                  // 右邻
            long long l = *prev(it);                  // 左邻
            gap.erase(gap.find(r - l));               // 原整段删除
            gap.insert(x - l);
            gap.insert(r - x);
        }
        else if(op == "remove"){
            long long x; cin >> x;
            auto it = pos.find(x);
            if(it == pos.end()) continue;             // 理论不会发生
            long long r = *next(it);
            long long l = *prev(it);
            gap.erase(gap.find(x - l));
            gap.erase(gap.find(r - x));
            gap.insert(r - l);                        // 合并成一段
            pos.erase(it);
        }
        else if(op == "query"){
            cout << *gap.rbegin() << '\n';            // 最大间距
        }
    }
    return 0;
}
