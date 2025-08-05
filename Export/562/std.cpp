#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

void solve() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> manual;
    for (int i = 0; i < n; ++i) {
        std::string theme;
        int page;
        std::cin >> theme >> page;
        manual[theme] = page;
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string query_theme;
        std::cin >> query_theme;
        // Using .find() is safer than operator[] if a key might not exist,
        // but the problem implies all queries are for existing themes.
        std::cout << manual[query_theme] << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
