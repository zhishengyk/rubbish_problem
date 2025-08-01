#include <iostream>
#include <algorithm>
using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 对于给定的x，找到使得gcd(x,y) + y最大的最小y值
int solve(int x) {
    int max_val = 0;
    int min_y = 1;
    
    // 遍历所有可能的y值
    for (int y = 1; y < x; y++) {
        int current_val = gcd(x, y) + y;
        if (current_val > max_val) {
            max_val = current_val;
            min_y = y;
        }
    }
    
    return min_y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
    
    return 0;
} 