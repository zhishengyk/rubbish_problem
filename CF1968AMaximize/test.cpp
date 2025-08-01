#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 测试std程序
    cout << "Testing std program..." << endl;
    
    // 创建测试输入
    ofstream test_in("test.in");
    test_in << "2\n";
    test_in << "7\n";
    test_in << "10\n";
    test_in.close();
    
    // 运行std程序
    system("./std < test.in > test.out");
    
    // 读取输出
    ifstream test_out("test.out");
    string line;
    cout << "Output:" << endl;
    while (getline(test_out, line)) {
        cout << line << endl;
    }
    test_out.close();
    
    // 清理
    system("rm test.in test.out");
    
    return 0;
} 