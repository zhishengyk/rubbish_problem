#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

struct Cow {
    int x, id;
};

bool compareCows(const Cow& a, const Cow& b) {
    return a.x < b.x;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<Cow> cows(n);
    std::set<int> breed_ids;
    for (int i = 0; i < n; ++i) {
        std::cin >> cows[i].x >> cows[i].id;
        breed_ids.insert(cows[i].id);
    }

    int total_breeds = breed_ids.size();
    
    std::sort(cows.begin(), cows.end(), compareCows);

    int min_cost = -1;

    int left = 0;
    std::map<int, int> window_counts;
    int breeds_in_window = 0;

    for (int right = 0; right < n; ++right) {
        // Add the right cow to the window
        int right_cow_id = cows[right].id;
        if (window_counts[right_cow_id] == 0) {
            breeds_in_window++;
        }
        window_counts[right_cow_id]++;

        // While the window is valid, try to shrink it from the left
        while (breeds_in_window == total_breeds) {
            int current_cost = cows[right].x - cows[left].x;
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }

            // Remove the left cow from the window
            int left_cow_id = cows[left].id;
            window_counts[left_cow_id]--;
            if (window_counts[left_cow_id] == 0) {
                breeds_in_window--;
            }
            left++;
        }
    }

    std::cout << min_cost << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
