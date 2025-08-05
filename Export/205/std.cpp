#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    long long min_cost = std::numeric_limits<long long>::max();

    for (int i = 0; i < 3; ++i) {
        int pencils_per_pack, price_per_pack;
        std::cin >> pencils_per_pack >> price_per_pack;

        // 计算需要购买的包数（向上取整）
        // k * pencils_per_pack >= n
        // k >= n / pencils_per_pack
        long long num_packs = (n + pencils_per_pack - 1) / pencils_per_pack;
        
        long long current_cost = num_packs * price_per_pack;

        if (current_cost < min_cost) {
            min_cost = current_cost;
        }
    }

    std::cout << min_cost << std::endl;

    return 0;
}
