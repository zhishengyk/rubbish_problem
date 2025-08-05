#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

/**
 * @brief 检查一个数的所有数字是否都在1-9的范围内且不重复
 * @param n 要检查的数
 * @param used_digits 用于记录已使用数字的数组
 * @return 如果所有数字都未使用过则返回true，否则返回false
 */
bool is_digits_unique(int n, std::vector<bool>& used_digits) {
    if (n < 100 || n > 999) return false;
    
    std::vector<bool> temp_used = used_digits;
    int hundreds = n / 100;
    int tens = (n / 10) % 10;
    int ones = n % 10;

    if (hundreds == 0 || tens == 0 || ones == 0) return false;
    if (temp_used[hundreds] || temp_used[tens] || temp_used[ones]) return false;
    if (hundreds == tens || hundreds == ones || tens == ones) return false;

    temp_used[hundreds] = true;
    temp_used[tens] = true;
    temp_used[ones] = true;
    
    used_digits = temp_used;
    return true;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    std::cin >> a >> b >> c;

    std::set<std::vector<int>> solutions;
    bool found = false;

    for (int i = 123; i <= 987; ++i) {
        if (i * c > 987 * a) continue;

        if ((i * b) % a == 0 && (i * c) % a == 0) {
            int num2 = i * b / a;
            int num3 = i * c / a;

            std::vector<bool> used(10, false);
            bool ok = true;

            int temp_i = i, temp_num2 = num2, temp_num3 = num3;
            
            used[temp_i % 10] = true; temp_i /= 10;
            if(used[temp_i % 10]) ok = false; used[temp_i % 10] = true; temp_i /= 10;
            if(used[temp_i % 10]) ok = false; used[temp_i % 10] = true; 

            if(used[temp_num2 % 10]) ok = false; used[temp_num2 % 10] = true; temp_num2 /= 10;
            if(used[temp_num2 % 10]) ok = false; used[temp_num2 % 10] = true; temp_num2 /= 10;
            if(used[temp_num2 % 10]) ok = false; used[temp_num2 % 10] = true; 

            if(used[temp_num3 % 10]) ok = false; used[temp_num3 % 10] = true; temp_num3 /= 10;
            if(used[temp_num3 % 10]) ok = false; used[temp_num3 % 10] = true; temp_num3 /= 10;
            if(used[temp_num3 % 10]) ok = false; used[temp_num3 % 10] = true;

            int count = 0;
            for(int k=1; k<=9; ++k) if(used[k]) count++;

            if(ok && count == 9 && !used[0]){
                 std::vector<int> sol = {i, num2, num3};
                 solutions.insert(sol);
                 found = true;
            }
        }
    }

    if (!found) {
        std::cout << "No!!!" << std::endl;
    } else {
        for (const auto& sol : solutions) {
            std::cout << sol[0] << " " << sol[1] << " " << sol[2] << std::endl;
        }
    }

    return 0;
}
