#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

struct Cow {
    int id;
    int x, h;
};

bool compareCows(const Cow& a, const Cow& b) {
    return a.x < b.x;
}

void solve() {
    int n;
    long long d;
    std::cin >> n >> d;
    std::vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        cows[i].id = i;
        std::cin >> cows[i].x >> cows[i].h;
    }

    std::sort(cows.begin(), cows.end(), compareCows);

    std::vector<bool> has_tall_left(n, false);
    std::deque<std::pair<int, int>> max_h_window_left; // {height, index_in_cows}
    int l_ptr = 0;
    for (int i = 0; i < n; ++i) {
        while (l_ptr < i && cows[i].x - cows[l_ptr].x > d) {
            if (!max_h_window_left.empty() && max_h_window_left.front().second == l_ptr) {
                max_h_window_left.pop_front();
            }
            l_ptr++;
        }
        if (!max_h_window_left.empty() && max_h_window_left.front().first >= 2 * cows[i].h) {
            has_tall_left[cows[i].id] = true;
        }
        while (!max_h_window_left.empty() && max_h_window_left.back().first <= cows[i].h) {
            max_h_window_left.pop_back();
        }
        max_h_window_left.push_back({cows[i].h, i});
    }

    std::vector<bool> has_tall_right(n, false);
    std::deque<std::pair<int, int>> max_h_window_right; // {height, index_in_cows}
    int r_ptr = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (r_ptr > i && cows[r_ptr].x - cows[i].x > d) {
            if (!max_h_window_right.empty() && max_h_window_right.front().second == r_ptr) {
                max_h_window_right.pop_front();
            }
            r_ptr--;
        }
        if (!max_h_window_right.empty() && max_h_window_right.front().first >= 2 * cows[i].h) {
            has_tall_right[cows[i].id] = true;
        }
        while (!max_h_window_right.empty() && max_h_window_right.back().first <= cows[i].h) {
            max_h_window_right.pop_back();
        }
        max_h_window_right.push_back({cows[i].h, i});
    }

    int crowded_cows = 0;
    for (int i = 0; i < n; ++i) {
        if (has_tall_left[i] && has_tall_right[i]) {
            crowded_cows++;
        }
    }

    std::cout << crowded_cows << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
