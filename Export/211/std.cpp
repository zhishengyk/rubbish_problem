#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <tuple>

// 返回一个元组 {等级, 点数和}
// 等级越小越强：1=豹子, 2=顺子, 3=对子, 4=散牌
std::tuple<int, int> get_score(int d1, int d2, int d3) {
    std::vector<int> dice = {d1, d2, d3};
    std::sort(dice.begin(), dice.end());
    
    int sum = dice[0] + dice[1] + dice[2];
    int level;

    // 豹子
    if (dice[0] == dice[1] && dice[1] == dice[2]) {
        level = 1;
    } 
    // 顺子
    else if (dice[0] + 1 == dice[1] && dice[1] + 1 == dice[2]) {
        level = 2;
    }
    // 对子
    else if (dice[0] == dice[1] || dice[1] == dice[2]) {
        level = 3;
    }
    // 散牌
    else {
        level = 4;
    }
    
    return {level, sum};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> a_dice(3), b_dice(3);
    std::cin >> a_dice[0] >> a_dice[1] >> a_dice[2];
    std::cin >> b_dice[0] >> b_dice[1] >> b_dice[2];

    auto score_a = get_score(a_dice[0], a_dice[1], a_dice[2]);
    auto score_b = get_score(b_dice[0], b_dice[1], b_dice[2]);

    int level_a = std::get<0>(score_a);
    int sum_a = std::get<1>(score_a);
    int level_b = std::get<0>(score_b);
    int sum_b = std::get<1>(score_b);

    // 处理特殊规则
    std::sort(a_dice.begin(), a_dice.end());
    if (a_dice[0] == 2 && a_dice[1] == 3 && a_dice[2] == 5 && level_b == 1) {
        std::cout << "A" << std::endl;
        return 0;
    }
    // 题目未说明反向特殊规则，但为严谨，也判断一下
    std::sort(b_dice.begin(), b_dice.end());
     if (b_dice[0] == 2 && b_dice[1] == 3 && b_dice[2] == 5 && level_a == 1) {
        std::cout << "B" << std::endl;
        return 0;
    }


    // 常规比较
    if (level_a < level_b) {
        std::cout << "A" << std::endl;
    } else if (level_a > level_b) {
        std::cout << "B" << std::endl;
    } else { // 等级相同
        if (sum_a > sum_b) {
            std::cout << "A" << std::endl;
        } else { // 包括和相同的情况，都算B赢
            std::cout << "B" << std::endl;
        }
    }

    return 0;
}
