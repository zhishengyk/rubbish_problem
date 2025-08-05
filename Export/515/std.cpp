#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t, n;
    std::cin >> t >> n;

    std::vector<int> pos, neg;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x > 0) {
            pos.push_back(x);
        } else {
            neg.push_back(-x);
        }
    }

    std::sort(pos.begin(), pos.end());
    std::sort(neg.begin(), neg.end());

    int max_landmarks = 0;

    // Strategy 1: Go negative, then positive
    for (int i = 0; i <= neg.size(); ++i) {
        long long time_spent = (i == 0) ? 0 : (long long)neg[i-1] * 2;
        if (time_spent > t) break;

        long long remaining_time = t - time_spent;
        auto it = std::upper_bound(pos.begin(), pos.end(), remaining_time);
        int pos_count = std::distance(pos.begin(), it);
        max_landmarks = std::max(max_landmarks, i + pos_count);
    }
    
    // Also consider going negative and staying there
    auto it_neg_only = std::upper_bound(neg.begin(), neg.end(), t);
    max_landmarks = std::max(max_landmarks, (int)std::distance(neg.begin(), it_neg_only));


    // Strategy 2: Go positive, then negative
    for (int i = 0; i <= pos.size(); ++i) {
        long long time_spent = (i == 0) ? 0 : (long long)pos[i-1] * 2;
        if (time_spent > t) break;
        
        long long remaining_time = t - time_spent;
        auto it = std::upper_bound(neg.begin(), neg.end(), remaining_time);
        int neg_count = std::distance(neg.begin(), it);
        max_landmarks = std::max(max_landmarks, i + neg_count);
    }

    // Also consider going positive and staying there
    auto it_pos_only = std::upper_bound(pos.begin(), pos.end(), t);
    max_landmarks = std::max(max_landmarks, (int)std::distance(pos.begin(), it_pos_only));

    std::cout << max_landmarks << std::endl;

    return 0;
}
