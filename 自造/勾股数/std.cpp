#include <bits/stdc++.h>
using namespace std;

/*
 判断三元组 (a,b,c) 是否为勾股数：
 存在 a^2 + b^2 = c^2（无序，先排序）
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b,c;
    while(cin>>a>>b>>c){
        long long x[3]={a,b,c};
        sort(x,x+3);
        if(x[0]<=0) { cout<<"NO\n"; continue;} // 非正整数直接否
        if(x[0]*x[0]+x[1]*x[1]==x[2]*x[2])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
