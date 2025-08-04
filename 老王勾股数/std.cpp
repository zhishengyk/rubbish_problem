#include <bits/stdc++.h>
using namespace std;
// 判断单组 (a,b,c) 是否构成勾股三元组，不考虑次序
static bool pyth(long long a,long long b,long long c){
    long long x[3]={a,b,c};
    sort(x,x+3);
    if(x[0]<=0) return false;
    // 额外要求：两条短边均 <= 60
    if(x[0] > 60 || x[1] > 60) return false;
    return x[0]*x[0]+x[1]*x[1]==x[2]*x[2];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        long long a,b,c;cin>>a>>b>>c;
        cout<<(pyth(a,b,c)?"YES":"NO")<<"\n";
    }
    return 0;
}