#include <iostream>
#include <string>
#include <vector>

void solve() {
    std::string s2, s1;
    int p;

    std::cin >> s2;
    std::cin >> s1;
    std::cin >> p;

    // The insert method inserts *before* the given position index.
    // To insert *after* the p-th character (which is at index p-1),
    // we need to insert at index p.
    s1.insert(p, s2);

    std::cout << s1 << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
