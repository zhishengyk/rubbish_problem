#include <iostream>
#include <vector>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 整数范围是10-5000，我们用一个布尔数组来标记数字是否出现过
    // 数组大小设为5001即可覆盖所有可能的整数
    std::vector<bool> seen(5001, false);
    
    bool first_output = true;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        if (num >= 10 && num <= 5000) {
            // 如果这个数字还没被看到过
            if (!seen[num]) {
                if (!first_output) {
                    std::cout << " ";
                }
                std::cout << num;
                first_output = false;
                
                // 标记为已看到
                seen[num] = true;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}
