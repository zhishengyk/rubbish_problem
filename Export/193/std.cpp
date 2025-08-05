#include <iostream>
#include <vector>
#include <iomanip>

int n, r;
std::vector<int> current_path;

/**
 * @brief 使用深度优先搜索生成组合
 * @param start_num 当前可以开始选择的最小数字
 */
void dfs(int start_num) {
    // 基础情况：如果已经选择了r个数字，则输出当前组合
    if (current_path.size() == r) {
        for (int i = 0; i < r; ++i) {
            std::cout << std::setw(3) << current_path[i];
        }
        std::cout << std::endl;
        return;
    }

    // 递归步骤：从start_num开始尝试每个数字
    for (int i = start_num; i <= n; ++i) {
        // 剪枝：如果剩下的数字不足以凑齐r个，则无需继续
        if (current_path.size() + (n - i + 1) < r) {
            break;
        }
        
        current_path.push_back(i); // 做出选择
        dfs(i + 1); // 进入下一层递归
        current_path.pop_back(); // 撤销选择（回溯）
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> r;

    dfs(1);

    return 0;
}
