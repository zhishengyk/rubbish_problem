#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int men_count, women_count;
    std::cin >> men_count >> women_count;
    int songs_count;
    std::cin >> songs_count;

    std::queue<int> men, women;
    for (int i = 1; i <= men_count; ++i) {
        men.push(i);
    }
    for (int i = 1; i <= women_count; ++i) {
        women.push(i);
    }

    for (int i = 0; i < songs_count; ++i) {
        int man = men.front();
        men.pop();
        int woman = women.front();
        women.pop();

        std::cout << man << " " << woman << std::endl;

        men.push(man);
        women.push(woman);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
