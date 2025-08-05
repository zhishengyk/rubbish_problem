#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        counts[num]++;
    }

    for (const auto& pair : counts) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
