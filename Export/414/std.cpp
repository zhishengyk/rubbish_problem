#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 定义病人结构体
struct Patient {
    std::string id;
    int age;
    int registration_order;
};

// 为老年人自定义的排序比较函数
bool compareSeniorPatients(const Patient& a, const Patient& b) {
    if (a.age != b.age) {
        return a.age > b.age; // 年龄大的在前
    }
    // 年龄相同，按登记顺序
    return a.registration_order < b.registration_order;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Patient> senior_patients;
    std::vector<Patient> other_patients;

    for (int i = 0; i < n; ++i) {
        Patient p;
        p.registration_order = i;
        std::cin >> p.id >> p.age;

        if (p.age >= 60) {
            senior_patients.push_back(p);
        } else {
            other_patients.push_back(p);
        }
    }

    // 对老年人进行排序
    std::sort(senior_patients.begin(), senior_patients.end(), compareSeniorPatients);

    // 非老年人本身就是按登记顺序的，无需排序

    // 输出老年人
    for (const auto& p : senior_patients) {
        std::cout << p.id << std::endl;
    }

    // 输出非老年人
    for (const auto& p : other_patients) {
        std::cout << p.id << std::endl;
    }

    return 0;
}
