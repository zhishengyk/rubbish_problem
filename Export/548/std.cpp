#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

void solve() {
    int n, k, p;
    std::cin >> n >> k >> p;

    std::list<int> deck;
    for (int i = 1; i <= k; ++i) {
        deck.push_back(i);
    }

    std::vector<int> xiaoming_cards;
    int current_player = 2;

    for (int i = 0; i < k; ++i) {
        if (current_player == 1) {
            xiaoming_cards.push_back(deck.front());
        }
        deck.pop_front();

        if (deck.empty()) break;

        for (int j = 0; j < p; ++j) {
            deck.push_back(deck.front());
            deck.pop_front();
        }

        current_player++;
        if (current_player > n) {
            current_player = 1;
        }
    }

    std::sort(xiaoming_cards.begin(), xiaoming_cards.end());

    for (size_t i = 0; i < xiaoming_cards.size(); ++i) {
        std::cout << xiaoming_cards[i] << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
