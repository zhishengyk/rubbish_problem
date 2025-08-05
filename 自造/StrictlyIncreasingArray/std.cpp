#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        long long ans=0;
        long long need = (long long)-4e18; // sufficiently small
        for(int i=0;i<n;++i){
            long long x; cin>>x;
            if(x>=need){
                need = x+1;
            }else{
                ans += need - x;
                ++need;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
