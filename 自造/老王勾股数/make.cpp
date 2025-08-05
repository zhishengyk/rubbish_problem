#include <bits/stdc++.h>
using namespace std;
/*
 * make.cpp
 * 生成随机测试数据到 1.in ，随后调用已编译好的 std 程序
 * 并写出对应答案 1.out
 * 在 Windows 下假设可执行文件名为 std.exe
 * 在 Linux/Mac 下假设为 ./std
 */

// 随机生成一组无序勾股三元组
static void genTriple(mt19937 &rng, ostream &out){
    uniform_int_distribution<int> dist(1, 30); // n,m 范围
    int n = dist(rng), m = dist(rng);
    if(n < m) swap(n, m);
    if(n == m) ++n;
    long long a = 1LL*n*n - 1LL*m*m;
    long long b = 2LL*n*m;
    long long c = 1LL*n*n + 1LL*m*m;
    vector<long long> v = {a,b,c};
    shuffle(v.begin(), v.end(), rng);
    out << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                // 要生成的测试组数
    if(!(cin >> T)) T = 10; // 若标准输入为空，则默认 10 组

    // 写入输入文件
    ofstream fin("1.in");
    fin << T << '\n';
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    for(int i=0;i<T;++i) genTriple(rng, fin);
    fin.close();

    // 调用标准解生成输出文件
#ifdef _WIN32
    system("std.exe < 1.in > 1.out");
#else
    system("./std < 1.in > 1.out");
#endif
    cerr << "[make] 已生成 1.in / 1.out\n";
    return 0;
}
