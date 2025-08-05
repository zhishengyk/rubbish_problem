#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::random_device rd;
    std::mt19937 rng(rd());

    const int NUM_TESTS = 10;            // 生成 10 组测试数据 1.in ~ 10.in
    for (int id = 1; id <= NUM_TESTS; ++id) {
        string inFile  = to_string(id) + ".in";
        string outFile = to_string(id) + ".out";

        std::ofstream fout(inFile);
        if (!fout) {
            cerr << "[Error] 无法创建输入文件 " << inFile << "\n";
            return 1;
        }

        // 决定本测试点的 n（数组长度）
        int n;
        if (id == 1)         n = 1;
        else if (id == 2)    n = 10;
        else if (id == 3)    n = 20;
        else if (id == 4)    n = 200;
        else if (id == 5)    n = 1'000;
        else                 n = std::uniform_int_distribution<int>(50'000, 100'000)(rng);

        fout << n << "\n";
        std::uniform_int_distribution<int> dist(1, 1'000'000'000);
        for (int i = 0; i < n; ++i) {
            fout << dist(rng) << "\n";
        }
        fout.close();

        // 利用标准程序生成输出
#ifdef _WIN32
        string cmd = ".\\std.exe < \"" + inFile + "\" > \"" + outFile + "\"";
#else
        string cmd = "./std < \"" + inFile + "\" > \"" + outFile + "\"";
#endif
        int ret = system(cmd.c_str());
        if (ret != 0) {
            cerr << "[Error] 运行标准程序失败，返回值 " << ret << " : " << cmd << "\n";
            return 1;
        }

        cout << "已生成测试点 " << id << "，n=" << n << "\n";
    }
    return 0;
}
