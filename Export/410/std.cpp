#include <iostream>
#include <string>
#include <vector>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int max_score = -1;
    std::string max_name;

    for (int i = 0; i < n; ++i) {
        int score;
        std::string name;
        std::cin >> score >> name;

        if (score > max_score) {
            max_score = score;
            max_name = name;
        }
    }

    std::cout << max_name << std::endl;

    return 0;
}
