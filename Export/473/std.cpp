#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Metal {
    double weight;
    double value;
    double unit_value;
};

bool compareMetals(const Metal& a, const Metal& b) {
    return a.unit_value > b.unit_value;
}

void solve() {
    double w;
    int s;
    std::cin >> w >> s;

    std::vector<Metal> metals(s);
    for (int i = 0; i < s; ++i) {
        std::cin >> metals[i].weight >> metals[i].value;
        if (metals[i].weight > 0) {
            metals[i].unit_value = metals[i].value / metals[i].weight;
        } else {
            metals[i].unit_value = 0; // Or handle as error
        }
    }

    std::sort(metals.begin(), metals.end(), compareMetals);

    double max_value = 0.0;
    double remaining_capacity = w;

    for (const auto& metal : metals) {
        if (remaining_capacity == 0) {
            break;
        }

        if (metal.weight <= remaining_capacity) {
            max_value += metal.value;
            remaining_capacity -= metal.weight;
        } else {
            max_value += remaining_capacity * metal.unit_value;
            remaining_capacity = 0;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << max_value << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;
    while (k--) {
        solve();
    }

    return 0;
}
