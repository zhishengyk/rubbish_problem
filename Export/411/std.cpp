#include <iostream>
#include <vector>
#include <algorithm>

// 定义选手结构体
struct Contestant {
    int id;
    int score;
};

// 自定义排序比较函数
bool compareContestants(const Contestant& a, const Contestant& b) {
    if (a.score != b.score) {
        return a.score > b.score; // 分数高的在前
    }
    return a.id < b.id; // 分数相同，ID小的在前
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<Contestant> contestants(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> contestants[i].id >> contestants[i].score;
    }

    // 按自定义规则排序
    std::sort(contestants.begin(), contestants.end(), compareContestants);

    // 计算面试线的人数
    int interview_count = static_cast<int>(m * 1.5);

    // 确定面试分数线
    int cutoff_score = contestants[interview_count - 1].score;

    // 确定实际进入面试的人数
    int actual_count = 0;
    for (int i = 0; i < n; ++i) {
        if (contestants[i].score >= cutoff_score) {
            actual_count++;
        } else {
            break; // 因为已经排序，后续选手分数更低
        }
    }

    // 输出第一行
    std::cout << cutoff_score << " " << actual_count << std::endl;

    // 输出进入面试的选手信息
    for (int i = 0; i < actual_count; ++i) {
        std::cout << contestants[i].id << " " << contestants[i].score << std::endl;
    }

    return 0;
}
