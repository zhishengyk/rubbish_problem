#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	
	// 生成10组数据
	for (int test = 1; test <= 10; test++) {
		string in_file = to_string(test) + ".in";
		string out_file = to_string(test) + ".out";
		
		ofstream fin(in_file);
		
		
			// 前5组是部分分数据：t=1, x<10
			int t = 100 ;
            
            while(t -- ){
                int c = uniform_int_distribution<>(1, 100)(gen);
                int a = uniform_int_distribution<>(1, 100)(gen);
                int b = uniform_int_distribution<>(1, 100)(gen);
                fin << c << " " << a << " " << b << endl;
            }
			
		
		
		fin.close();
		
		// 调用std.cpp生成输出
#ifdef _WIN32
		// Windows 在 redirection (<, >) 外不能把整条命令包进双引号，否则 cmd 解析失败。
		// 保持文件名加引号，程序名前加 ./ 或 .\ 均可，这里用 .\ 以符合 Windows 习惯。
		string command = ".\\std.exe < \"" + in_file + "\" > \"" + out_file + "\"";
#else
		// POSIX 系统维持原来的 ./std 调用
		string command = "./std < \"" + in_file + "\" > \"" + out_file + "\"";
#endif
		int ret = system(command.c_str());
		if (ret != 0) {
			cerr << "[Error] command failed with code " << ret << " : " << command << endl;
			return 1; // 立即终止，方便定位问题
		}
		
		cout << "Generated test " << test << endl;
	}
	
	return 0;
}
