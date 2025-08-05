#include <iostream>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_money = 100;
    int solutions_count = 0;

    // 枚举10元商品的数量x，范围从1到9
    // 最多买9个10元，因为5元和1元的商品至少各买一个
    for (int x = 1; x * 10 < total_money - 5 - 1; ++x) {
        // 枚举5元商品的数量y
        // 剩余的钱至少要够买一个1元的商品
        for (int y = 1; x * 10 + y * 5 < total_money - 1; ++y) {
            // 计算1元商品的数量z
            int z = total_money - x * 10 - y * 5;
            
            // 如果z是正数，说明这是一个有效的方案
            if (z > 0) {
                solutions_count++;
            }
        }
    }

    // 输出总的方案数
    std::cout << "总共有 " << solutions_count << " 种购买方案。" << std::endl;

    return 0;
}
