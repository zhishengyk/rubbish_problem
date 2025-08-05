#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_money, price1, price2;
    std::cin >> total_money >> price1 >> price2;

    int big_price, small_price;
    bool price1_is_big;

    if (price1 > price2) {
        big_price = price1;
        small_price = price2;
        price1_is_big = true;
    } else {
        big_price = price2;
        small_price = price1;
        price1_is_big = false;
    }

    // 枚举价格高的碗的数量
    for (int i = 2; i * big_price < total_money; i += 2) {
        int remaining_money = total_money - i * big_price;
        if (remaining_money > 0 && remaining_money % small_price == 0) {
            int small_count = remaining_money / small_price;
            if (small_count >= 2 && small_count % 2 == 0) {
                if (price1_is_big) {
                    std::cout << i << " " << small_count << std::endl;
                } else {
                    std::cout << small_count << " " << i << std::endl;
                }
            }
        }
    }

    return 0;
}
