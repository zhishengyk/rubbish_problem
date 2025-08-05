#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    std::unordered_set<int> s_numbers;
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        s_numbers.insert(s[i]);
    }

    std::map<int, int> mapping;
    std::vector<int> t(n);
    int next_t_num = 1;

    for (int i = 0; i < n; ++i) {
        int current_s_num = s[i];
        if (mapping.count(current_s_num)) {
            t[i] = mapping[current_s_num];
        } else {
            // Find the next available number for T
            while (s_numbers.count(next_t_num)) {
                next_t_num++;
            }
            mapping[current_s_num] = next_t_num;
            t[i] = next_t_num;
            next_t_num++;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << t[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
