#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> result;
    
    // 从一个足够大的2的幂开始，向下贪心
    // 2^23 < 10^7 < 2^24
    int power_of_2 = 1;
    while(power_of_2 <= n / 2) {
        power_of_2 *= 2;
    }


    while (n > 0 && power_of_2 >= 2) {
        if (n >= power_of_2) {
            result.push_back(power_of_2);
            n -= power_of_2;
        }
        power_of_2 /= 2;
    }

    if (n != 0) {
        // 理论上偶数一定能分解完，如果n不为0说明逻辑有误
        // 但根据题意，偶数一定有解，这里作为保险
        std::cout << -1 << std::endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
