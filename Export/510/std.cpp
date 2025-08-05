#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool check(long long max_expense_limit, int n, int m, const std::vector<int>& expenses) {
    int month_count = 1;
    long long current_month_expense = 0;
    for (int expense : expenses) {
        if (expense > max_expense_limit) return false; // Single day's expense exceeds limit
        if (current_month_expense + expense <= max_expense_limit) {
            current_month_expense += expense;
        } else {
            month_count++;
            current_month_expense = expense;
        }
    }
    return month_count <= m;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> expenses(n);
    long long total_expense = 0;
    int max_daily_expense = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> expenses[i];
        total_expense += expenses[i];
        if (expenses[i] > max_daily_expense) {
            max_daily_expense = expenses[i];
        }
    }

    long long left = max_daily_expense, right = total_expense, ans = total_expense;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n, m, expenses)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
