#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

// 使用 mt19937 提供高质量的随机数
mt19937 gen(random_device{}());

void generate_test_case(int test_num) {
    string in_file = to_string(test_num) + ".in";
    ofstream fout(in_file);

    int n;
    long long k;
    vector<int> a;
    
    // 50% of data: n <= 100 (Test 1-10)
    if (test_num <= 10) {
        n = uniform_int_distribution<>(10, 100)(gen);
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            a[i] = uniform_int_distribution<>(0, 100000)(gen);
        }
    } 
    // 100% data: n <= 1000 (Test 11-20)
    else {
        n = uniform_int_distribution<>(900, 1000)(gen);
        a.resize(n);
        
        // Tests 11-15: random values
        if (test_num <= 15) {
             for (int i = 0; i < n; ++i) {
                a[i] = uniform_int_distribution<>(0, 1000000000)(gen);
            }
        } 
        // Tests 16-18: arithmetic progression
        else if (test_num <= 18) {
            int start = uniform_int_distribution<>(0, 100000000)(gen);
            int diff = uniform_int_distribution<>(1, 1000)(gen);
            for (int i = 0; i < n; ++i) {
                a[i] = start + i * diff;
            }
        }
        // Tests 19-20: with many duplicate elements
        else {
            int distinct_count = uniform_int_distribution<>(50, 150)(gen);
            vector<int> distinct_elements(distinct_count);
            for (int i = 0; i < distinct_count; ++i) {
                distinct_elements[i] = uniform_int_distribution<>(0, 1000000000)(gen);
            }
            for (int i = 0; i < n; ++i) {
                a[i] = distinct_elements[uniform_int_distribution<>(0, distinct_count - 1)(gen)];
            }
        }
    }

    long long max_k = (long long)n * (n - 1) / 2;
    if (max_k == 0) {
        k = 1; 
    } else {
       k = uniform_int_distribution<long long>(1, max_k)(gen);
    }

    fout << n << " " << k << "\n";
    shuffle(a.begin(), a.end(), gen);

    for (int i = 0; i < n; ++i) {
        fout << a[i] << (i == n - 1 ? "" : " ");
    }
    fout << "\n";
    fout.close();
}


int main() {
    // 这段代码假设它在 "第K小差值" 文件夹内被编译和执行
    // 1. 先编译 std.cpp
    int compile_std_ret = system("g++ -std=c++17 -O2 std.cpp -o std.exe");
    if (compile_std_ret != 0) {
        cerr << "[Error] Compilation failed for std.cpp" << endl;
        return 1;
    }
    cout << "std.cpp compiled successfully." << endl;

    // 2. 循环生成测试数据并调用 std.exe
    for (int i = 1; i <= 20; ++i) {
        generate_test_case(i);
        string in_file = to_string(i) + ".in";
        string out_file = to_string(i) + ".out";

        string command;
#ifdef _WIN32
        command = ".\\std.exe < " + in_file + " > " + out_file;
#else
        command = "./std < " + in_file + " > " + out_file;
#endif

        int run_ret = system(command.c_str());
        if (run_ret != 0) {
            cerr << "[Error] Command failed for test " << i << ": " << command << endl;
            return 1;
        }

        cout << "Generated test case " << i << " successfully." << endl;
    }

    return 0;
}
