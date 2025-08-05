#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Fish {
    int id;
    double stock;
    double total_price;
    double unit_price;
};

bool compareFish(const Fish& a, const Fish& b) {
    return a.unit_price > b.unit_price;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    double d;
    std::cin >> n >> d;

    std::vector<double> stocks(n);
    std::vector<double> prices(n);
    std::vector<Fish> fishes(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> stocks[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    for (int i = 0; i < n; ++i) {
        fishes[i].id = i;
        fishes[i].stock = stocks[i];
        fishes[i].total_price = prices[i];
        if (stocks[i] > 0) {
            fishes[i].unit_price = prices[i] / stocks[i];
        } else {
            fishes[i].unit_price = 0;
        }
    }

    std::sort(fishes.begin(), fishes.end(), compareFish);

    double max_revenue = 0.0;
    double remaining_demand = d;

    for (const auto& fish : fishes) {
        if (remaining_demand == 0) {
            break;
        }

        if (fish.stock >= remaining_demand) {
            max_revenue += remaining_demand * fish.unit_price;
            remaining_demand = 0;
        } else {
            max_revenue += fish.total_price;
            remaining_demand -= fish.stock;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << max_revenue << std::endl;

    return 0;
}
