#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

void solve() {
    int n;
    long long p;
    while (std::cin >> n >> p) {
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        std::unordered_set<long long> visited;
        int total_max_subset_size = 0;

        for (int i = 0; i < n; ++i) {
            if (visited.count(a[i])) {
                continue;
            }

            // a[i] is the start of a new chain since the array is sorted
            // and we haven't visited it yet.
            int chain_length = 0;
            long long current_num = a[i];

            while (std::binary_search(a.begin(), a.end(), current_num)) {
                visited.insert(current_num);
                chain_length++;
                // Check for potential overflow before multiplication
                if (__builtin_mul_overflow(current_num, p, &current_num)) {
                    // If overflow, the chain ends here.
                    break;
                }
            }
            total_max_subset_size += (chain_length + 1) / 2;
        }
        std::cout << total_max_subset_size << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
