#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_VAL = 1000001;
bool seen[MAX_VAL] = {false};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] < MAX_VAL) {
            seen[a[i]] = true;
        }
    }

    int x;
    std::cin >> x;

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int complement = x - a[i];
        
        // Ensure we count each pair only once by demanding a[i] < complement.
        // This also implicitly handles the case where a[i] == complement,
        // since a[i] < a[i] is false. This is correct as the problem
        // states distinct integers, so a[i] can't equal its complement.
        if (a[i] < complement) {
            if (complement > 0 && complement < MAX_VAL && seen[complement]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
