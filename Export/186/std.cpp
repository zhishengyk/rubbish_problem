#include <iostream>
#include <vector>
#include <numeric>

// 全局变量，用于存储目标美味程度、所有解决方案和当前搜索路径
int n;
std::vector<std::vector<int>> solutions;
std::vector<int> current_path;

/**
 * @brief 使用深度优先搜索查找所有配料组合
 * @param ingredient_index 当前处理的配料索引（从0到9）
 * @param current_sum 当前已选配料的重量总和
 */
void dfs(int ingredient_index, int current_sum) {
    // 基础情况：如果10种配料都已选择完毕
    if (ingredient_index == 10) {
        // 如果当前总和恰好等于目标值n，则找到一个有效方案
        if (current_sum == n) {
            solutions.push_back(current_path);
        }
        return;
    }

    // 递归步骤：为当前配料尝试1, 2, 3克三种重量
    for (int weight = 1; weight <= 3; ++weight) {
        // 剪枝优化：如果加入当前重量后总和会超过n，则无需继续
        if (current_sum + weight <= n) {
            current_path.push_back(weight); // 做出选择
            dfs(ingredient_index + 1, current_sum + weight); // 进入下一层递归
            current_path.pop_back(); // 撤销选择（回溯）
        }
    }
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 读取输入
    std::cin >> n;

    // 从第0个配料，总和为0开始搜索
    dfs(0, 0);

    // 输出方案总数
    std::cout << solutions.size() << std::endl;

    // 按字典序输出每种方案
    for (const auto& sol : solutions) {
        for (int i = 0; i < sol.size(); ++i) {
            std::cout << sol[i] << (i == sol.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
