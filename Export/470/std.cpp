#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int end;
};

bool compareActivities(const Activity& a, const Activity& b) {
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

    std::vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> activities[i].start >> activities[i].end;
    }

    std::sort(activities.begin(), activities.end(), compareActivities);

    int count = 0;
    int last_end_time = -1; 

    for (const auto& act : activities) {
        if (act.start >= last_end_time) {
            count++;
            last_end_time = act.end;
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}
