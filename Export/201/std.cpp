#include <iostream>
#include <string>
#include <vector>
#include <cmath>

void calculate_and_print(const std::string& record, int target_score) {
    int score_a = 0;
    int score_b = 0;

    for (char result : record) {
        if (result == 'W') {
            score_a++;
        } else if (result == 'L') {
            score_b++;
        }

        if ((score_a >= target_score || score_b >= target_score) && std::abs(score_a - score_b) >= 2) {
            std::cout << score_a << ":" << score_b << std::endl;
            score_a = 0;
            score_b = 0;
        }
    }
    // 输出最后一局（可能未结束）的比分
    std::cout << score_a << ":" << score_b << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::string full_record;
    while (std::cin >> line) {
        for (char c : line) {
            if (c == 'E') {
                goto end_input;
            }
            full_record += c;
        }
    }

end_input:
    calculate_and_print(full_record, 11);
    std::cout << std::endl;
    calculate_and_print(full_record, 21);

    return 0;
}
