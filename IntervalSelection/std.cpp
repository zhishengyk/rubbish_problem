#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start >> activities[i].end;
    }

    sort(activities.begin(), activities.end(), compareActivities);

    int count = 0;
    long long last_end_time = -2e9 - 7; 

    if (n > 0) {
        count = 1;
        last_end_time = activities[0].end;
    } else {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= last_end_time + k) {
            count++;
            last_end_time = activities[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
