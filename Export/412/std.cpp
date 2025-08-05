#include <iostream>
#include <vector>
#include <algorithm>

// 定义学生结构体
struct Student {
    int id;
    int score_base;
    int score_algo;
    int score_prac;
    int total_score;
};

// 自定义排序比较函数
bool compareStudents(const Student& a, const Student& b) {
    // 第一优先级：总分
    if (a.total_score != b.total_score) {
        return a.total_score > b.total_score; // 总分高的在前
    }
    // 第二优先级：计算机基础成绩
    if (a.score_base != b.score_base) {
        return a.score_base > b.score_base; // 基础分高的在前
    }
    // 第三优先级：学号
    return a.id < b.id; // 学号小的在前
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        students[i].id = i + 1; // 学号从1开始
        std::cin >> students[i].score_base >> students[i].score_algo >> students[i].score_prac;
        students[i].total_score = students[i].score_base + students[i].score_algo + students[i].score_prac;
    }

    // 按自定义规则排序
    std::sort(students.begin(), students.end(), compareStudents);

    // 输出前5名学生的信息
    for (int i = 0; i < 5 && i < n; ++i) {
        std::cout << students[i].id << " " << students[i].total_score << std::endl;
    }

    return 0;
}
