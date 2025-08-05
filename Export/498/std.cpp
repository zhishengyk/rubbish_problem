#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> burp_people(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> burp_people[i];
    }

    std::unordered_set<int> fart_people;
    for (int i = 0; i < m; ++i) {
        int person;
        std::cin >> person;
        fart_people.insert(person);
    }

    bool first = true;
    for (int person : burp_people) {
        if (fart_people.count(person)) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << person;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
