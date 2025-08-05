#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, r;
    std::cin >> n >> r;

    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    // Sort people by their water-fetching time in ascending order
    std::sort(t.begin(), t.end());

    // tap_times[j] = the time when tap j becomes free
    std::vector<long long> tap_times(r, 0);
    long long total_time = 0;

    // Distribute people to taps
    for (int i = 0; i < n; ++i) {
        // Find the tap that frees up the earliest
        // For small r, linear search is fine. For large r, a min-priority_queue would be better.
        auto min_it = std::min_element(tap_times.begin(), tap_times.end());
        
        // This person's waiting time is the time the earliest tap becomes free
        long long waiting_time = *min_it;
        
        // This person's total time spent is waiting_time + serving_time
        total_time += waiting_time + t[i];
        
        // Update the finish time for the chosen tap
        *min_it += t[i];
    }

    std::cout << total_time << std::endl;

    return 0;
}
