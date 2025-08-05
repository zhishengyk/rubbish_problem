#include <iostream>
#include <vector>
#include <deque>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> min_results;
    std::vector<int> max_results;
    std::deque<int> min_dq;
    std::deque<int> max_dq;

    for (int i = 0; i < n; ++i) {
        // Remove elements outside the window
        if (!min_dq.empty() && min_dq.front() <= i - k) {
            min_dq.pop_front();
        }
        if (!max_dq.empty() && max_dq.front() <= i - k) {
            max_dq.pop_front();
        }

        // Maintain monotonic properties
        while (!min_dq.empty() && a[min_dq.back()] >= a[i]) {
            min_dq.pop_back();
        }
        while (!max_dq.empty() && a[max_dq.back()] <= a[i]) {
            max_dq.pop_back();
        }

        // Add current element
        min_dq.push_back(i);
        max_dq.push_back(i);

        // Store results
        if (i >= k - 1) {
            min_results.push_back(a[min_dq.front()]);
            max_results.push_back(a[max_dq.front()]);
        }
    }

    for (size_t i = 0; i < min_results.size(); ++i) {
        std::cout << min_results[i] << (i == min_results.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    for (size_t i = 0; i < max_results.size(); ++i) {
        std::cout << max_results[i] << (i == max_results.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
