#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> people(n);
    std::iota(people.begin(), people.end(), 1);

    int current_pos = 0;
    while (!people.empty()) {
        current_pos = (current_pos + m - 1) % people.size();
        std::cout << people[current_pos] << " ";
        people.erase(people.begin() + current_pos);
    }
    std::cout << std::endl;

    return 0;
}
