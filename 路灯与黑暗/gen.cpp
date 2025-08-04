#include <bits/stdc++.h>
using namespace std;

auto rng = std::mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());

// 生成一次随机测试数据并写入文件，再调用 std 生成输出
auto generate_one = [](int idx){
    string in_file = to_string(idx) + ".in";
    string out_file = to_string(idx) + ".out";

    ofstream fout(in_file);

    // 随机道路长度
    long long L;
    int m;
    if(idx <= 5){
        // 小规模
        L = uniform_int_distribution<long long>(20, 100)(rng);
        m = uniform_int_distribution<int>(10, 50)(rng);
    }else if(idx <= 12){
        // 中等规模
        L = uniform_int_distribution<long long>(1000, 100000)(rng); // 1e3 ~ 1e5
        m = uniform_int_distribution<int>(100, 5000)(rng);
    }else{
        // 大规模 - 增加操作数量，特别是query
        L = uniform_int_distribution<long long>(100000000, 1000000000)(rng); // 1e8 ~ 1e9
        m = uniform_int_distribution<int>(100000, 200000)(rng); // 增加操作数
    }

    fout << L << ' ' << m << '\n';

    set<long long> pos{0, L};
    vector<pair<string,long long>> ops;

    // 根据测试点类型调整操作分布
    int add_prob, remove_prob, query_prob;
    if(idx <= 5){
        // 小规模：平衡分布
        add_prob = 45; remove_prob = 35; query_prob = 20;
    }else if(idx <= 12){
        // 中等规模：大量add，少量remove，大量query
        add_prob = 60; remove_prob = 10; query_prob = 30;
    }else{
        // 大规模：极多add，极少remove，极多query
        add_prob = 70; remove_prob = 5; query_prob = 25;
    }

    for(int i=0;i<m;++i){
        int t = uniform_int_distribution<int>(0, 99)(rng);
        if(t < add_prob){
            // add - 大量添加路灯
            long long x = uniform_int_distribution<long long>(1, L-1)(rng);
            ops.push_back({"add", x});
            pos.insert(x);
        }else if(t < add_prob + remove_prob && pos.size()>2){
            // remove - 少量移除路灯
            // 随机选择可移除路灯
            int k = uniform_int_distribution<int>(1, (int)pos.size()-2)(rng); // 1..size-2  跳过端点
            auto it = next(pos.begin(), k);
            long long x = *it;
            ops.push_back({"remove", x});
            pos.erase(it);
        }else{
            // query - 大量查询
            ops.push_back({"query", -1});
        }
    }

    // 写入文件
    for(auto &pr: ops){
        if(pr.first == "query") fout << pr.first << '\n';
        else fout << pr.first << ' ' << pr.second << '\n';
    }

    fout.close();

    // 调用已编译好的 std 生成正确答案
#ifdef _WIN32
    string cmd = ".\\std.exe < \"" + in_file + "\" > \"" + out_file + "\"";
#else
    string cmd = "./std < \"" + in_file + "\" > \"" + out_file + "\"";
#endif
    int ret = system(cmd.c_str());
    if(ret!=0){
        cerr << "[Error] failed when running std on "<<in_file<<"\n";
        exit(1);
    }
    cerr << "Generated case #"<<idx<<"\n";
};

int main(){
    ios::sync_with_stdio(false);
    // 生成 20 组测试数据
    for(int i=1;i<=20;++i){
        generate_one(i);
    }
    return 0;
}
