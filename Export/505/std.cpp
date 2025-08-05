#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::unordered_map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        counts[num]++;
    }

    std::vector<int> intersection;
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        if (counts.count(num) && counts[num] > 0) {
            intersection.push_back(num);
            counts[num]--;
        }
    }

    std::sort(intersection.begin(), intersection.end());

    for (int i = 0; i < intersection.size(); ++i) {
        std::cout << intersection[i] << (i == intersection.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
