#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 0;
    int last_point_position = -1; // Initialize with a value smaller than any possible start

    for (const auto& interval : intervals) {
        // If the current interval is not covered by the last point we placed
        if (interval.start > last_point_position) {
            // We need a new point. Place it at the end of the current interval.
            count++;
            last_point_position = interval.end;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
