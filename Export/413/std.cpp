#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <functional>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> males;
    std::vector<double> females;

    for (int i = 0; i < n; ++i) {
        std::string gender;
        double height;
        std::cin >> gender >> height;
        if (gender == "male") {
            males.push_back(height);
        } else {
            females.push_back(height);
        }
    }

    // 男生按身高升序排序
    std::sort(males.begin(), males.end());

    // 女生按身高降序排序
    std::sort(females.begin(), females.end(), std::greater<double>());

    // 设置输出格式
    std::cout << std::fixed << std::setprecision(2);

    // 输出男生身高
    bool first = true;
    for (double height : males) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << height;
        first = false;
    }

    // 输出女生身高
    for (double height : females) {
        // 如果男生列表非空，则第一个女生前面肯定有空格
        // 如果男生列表为空，则第一个女生是第一个输出，不需要空格
        if (!first || !males.empty()) {
             std::cout << " ";
        }
        std::cout << height;
        first = false; // 保证后续输出都有空格
    }
    std::cout << std::endl;

    return 0;
}
