#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    // 15x + 9y + z = 3n
    // x + y + z = m
    // -> 14x + 8y = 3n - m
    // -> 7x + 4y = (3n - m) / 2
    
    int target = 3 * n - m;
    if (target < 0 || target % 2 != 0) {
        // 无解的情况
        return 0;
    }
    
    target /= 2;

    // 枚举公鸡的数量x
    for (int x = 0; 7 * x <= target; ++x) {
        int remaining = target - 7 * x;
        
        if (remaining >= 0 && remaining % 4 == 0) {
            int y = remaining / 4;
            int z = m - x - y;
            
            if (z >= 0 && (x + y + z == m)) {
                std::cout << x << " " << y << " " << z << std::endl;
            }
        }
    }

    return 0;
}
