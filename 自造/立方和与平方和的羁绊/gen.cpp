#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

    int T = 195;
    std::cout << T << std::endl;

    std::set<int> generated_nums;
    
    // Add specific positive cases from the problem description
    generated_nums.insert(1);
    generated_nums.insert(3);
    generated_nums.insert(29);

    // Add some specific negative cases
    generated_nums.insert(-1);
    generated_nums.insert(-10);
    generated_nums.insert(-299);

    // Generate random positive numbers
    int positive_count = (T - generated_nums.size()) / 2;
    for(int i = 0; i < positive_count; ++i) {
        int n;
        do {
            n = std::uniform_int_distribution<int>(0, 299)(rng);
        } while (generated_nums.count(n));
        generated_nums.insert(n);
    }

    // Generate random negative numbers
    while (generated_nums.size() < T) {
        int n;
        do {
            n = std::uniform_int_distribution<int>(-299, -1)(rng);
        } while (generated_nums.count(n));
        generated_nums.insert(n);
    }
    
    // Output all numbers in a shuffled order
    std::vector<int> nums_vec(generated_nums.begin(), generated_nums.end());
    std::shuffle(nums_vec.begin(), nums_vec.end(), rng);

    for (int num : nums_vec) {
        std::cout << num << std::endl;
    }

    return 0;
}
