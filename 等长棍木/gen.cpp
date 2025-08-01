#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
using int64 = long long;

/*
 * 数据分层（共 10 组）
 *  1-2  : tiny   N<=20      L<=100      K<=1000                一定可行
 *  3-5  : medium N<=10000   L<=1e6      K 随机(可能无解)      
 *  6-10 : large  N=2e5      L<=1e9      K 随机(可能无解)
 *  每组写入 input i.in，随后调用同目录下 std.exe/std 生成 i.out
 */

int main(){
    random_device rd;
    mt19937_64 rng(rd());

    // 检查并编译 std 解答
#ifdef _WIN32
    const string exeName = "std.exe";
    if(!std::filesystem::exists(exeName)){
        cout << "[Info] std.exe not found, compiling...\n";
        if(system("g++ -O2 -std=c++17 std.cpp -o std.exe")){
            cerr << "Failed to compile std.cpp\n"; return 1;
        }
    }
#else
    const string exeName = "std";
    if(!std::filesystem::exists(exeName)){
        cout << "[Info] std not found, compiling...\n";
        if(system("g++ -O2 -std=c++17 std.cpp -o std")){
            cerr << "Failed to compile std.cpp\n"; return 1;
        }
    }
#endif

    for(int tc=1; tc<=10; ++tc){
        string inFile = to_string(tc)+".in";
        string outFile= to_string(tc)+".out";
        ofstream fout(inFile);

        int n; int64 k; vector<int64> a;
        if(tc<=2){               // tiny 保证可行
            n = uniform_int_distribution<int>(1,20)(rng);
            a.resize(n);
            int64 sum = 0;
            for(auto &x:a){
                x = uniform_int_distribution<int>(1,100)(rng);
                sum += x;
            }
            k = uniform_int_distribution<int64>(1, sum)(rng); // 一定可行
        }else if(tc<=5){         // medium 随机 可行或不可行
            n = uniform_int_distribution<int>(1000,10000)(rng);
            a.resize(n);
            int64 sum = 0;
            for(auto &x:a){
                x = uniform_int_distribution<int>(1,1000000)(rng);
                sum += x;
            }
            // 50% 生成可行值，50% 生成不可行值
            if(uniform_int_distribution<int>(0,1)(rng))
                k = uniform_int_distribution<int64>(1, sum)(rng); // 可行
            else
                k = sum + uniform_int_distribution<int64>(1, n)(rng); // 无解
        }else{                   // large
            n = 200000;
            a.resize(n);
            int64 sum = 0;
            for(auto &x:a){
                x = uniform_int_distribution<int>(1, 1000000000)(rng);
                sum += x;
            }
            if(uniform_int_distribution<int>(0,2)(rng)==0) // 三分之一生成不可行
                k = sum + uniform_int_distribution<int64>(1, n)(rng);
            else
                k = uniform_int_distribution<int64>(1, sum)(rng);
        }

        fout << n << ' ' << k << "\n";
        for(int i=0;i<n;++i){
            fout << a[i] << (i+1==n?'\n':' ');
        }
        fout.close();

#ifdef _WIN32
        string cmd = "std.exe < \""+inFile+"\" > \""+outFile+"\"";
#else
        string cmd = "./std < \""+inFile+"\" > \""+outFile+"\"";
#endif
        if(system(cmd.c_str())!=0){
            cerr << "Failed on test "<<tc<<"\n";
            return 1;
        }
        cout << "Generated test "<<tc<<"\n";
    }
    return 0;
} 