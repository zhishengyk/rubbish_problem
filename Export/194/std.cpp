#include <iostream>
#include <vector>
#include <iomanip>

int n;
std::vector<int> current_path;
std::vector<bool> used;

/**
 * @brief 使用深度优先搜索生成全排列
 */
void dfs() {
    // 基础情况：如果当前排列的长度等于n，则输出
    if (current_path.size() == n) {
        for (int i = 0; i < n; ++i) {
            std::cout << std::setw(5) << current_path[i];
        }
        std::cout << std::endl;
        return;
    }

    // 递归步骤：从1到n尝试每个数字
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;           // 标记为已使用
            current_path.push_back(i); // 做出选择
            dfs();                    // 进入下一层递归
            current_path.pop_back();  // 撤销选择（回溯）
            used[i] = false;          // 取消标记
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    used.resize(n + 1, false);

    dfs();

    return 0;
}
