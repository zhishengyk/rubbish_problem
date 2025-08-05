#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

struct Cow {
    int x, id;
};

bool compareCows(const Cow& a, const Cow& b) {
    return a.x < b.x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

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

    int left = 0;
    long long min_cost = -1;
    std::map<int, int> window_counts;
    int unique_breeds_in_window = 0;

    for (int right = 0; right < n; ++right) {
        if (window_counts[cows[right].id] == 0) {
            unique_breeds_in_window++;
        }
        window_counts[cows[right].id]++;

        while (unique_breeds_in_window == total_breeds) {
            long long current_cost = (long long)cows[right].x - cows[left].x;
            if (min_cost == -1 || current_cost < min_cost) {
                min_cost = current_cost;
            }

            window_counts[cows[left].id]--;
            if (window_counts[cows[left].id] == 0) {
                unique_breeds_in_window--;
            }
            left++;
        }
    }

    std::cout << min_cost << std::endl;

    return 0;
}
