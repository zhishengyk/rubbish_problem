#include <bits/stdc++.h>
using namespace std;

bool isValley(const string &s){
    int n = (int)s.size();
    if(n < 3) return false; // 至少要有下降和上升两段
    int i = 0;
    // 严格下降
    while(i + 1 < n && s[i] > s[i+1]) ++i;
    if(i == 0 || i == n-1) return false; // 没有下降或没有上升
    // 峰谷底部 s[i] 是谷底，需要严格上升
    int j = i;
    while(j + 1 < n && s[j] < s[j+1]) ++j;
    if(j != n-1) return false; // 后面存在非严格上升
    // 同时还需要保证下降段严格，也就是我们在while里用的 > 已经保证
    // 另外需确保不存在相等情况，已在比较里排除
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        string s; cin >> s;
        if(isValley(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
