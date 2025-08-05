#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
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

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    long long total_length = 0;
    Interval current_merged = intervals[0];

    for (int i = 1; i < n; ++i) {
        if (intervals[i].start < current_merged.end) {
            current_merged.end = std::max(current_merged.end, intervals[i].end);
        } else {
            total_length += (long long)current_merged.end - current_merged.start;
            current_merged = intervals[i];
        }
    }

    total_length += (long long)current_merged.end - current_merged.start;

    std::cout << total_length << std::endl;

    return 0;
}
