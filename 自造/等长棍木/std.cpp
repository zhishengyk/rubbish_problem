#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; int64 k;
    if(!(cin>>n>>k)) return 0;
    vector<int64> a(n);
    int64 mx = 0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    if(k==0){
        cout<<0<<"\n";
        return 0;
    }

    auto ok = [&](int64 x)->bool{
        if(x==0) return true;
        __int128 tot = 0; // 防止溢出
        for(auto len: a){
            tot += len / x;
            if(tot >= k) return true; // 及早结束
        }
        return false;
    };

    int64 l=1, r=mx, ans=0;
    while(l<=r){
        int64 mid = (l+r)>>1;
        if(ok(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
} 