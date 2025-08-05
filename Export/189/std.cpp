#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_cost = 40;
    int adult_price = 8;
    int child_price = 3;

    std::vector<std::pair<int, int>> solutions;

    // 枚举成人的人数x，范围从1到4
    // 最多4个成人，因为儿童至少有1人
    for (int adults = 1; adults * adult_price < total_cost; ++adults) {
        int remaining_cost = total_cost - adults * adult_price;
        
        // 检查剩余的钱是否能被儿童票价整除
        if (remaining_cost > 0 && remaining_cost % child_price == 0) {
            int children = remaining_cost / child_price;
            solutions.push_back({adults, children});
        }
    }

    // 按成人数量升序输出（默认已满足）
    for (const auto& sol : solutions) {
        std::cout << sol.first << " " << sol.second << std::endl;
    }

    return 0;
}
