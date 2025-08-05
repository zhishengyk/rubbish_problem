#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查函数：计算有多少个数对的差值小于等于 mid
long long count_le(int mid, int n, vector<int>& a) {
    long long count = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && a[j] - a[i] <= mid) {
            j++;
        }
        count += (j - i - 1);
    }
    return count;
}

// 另一个检查函数的实现，使用 std::upper_bound
long long count_le_upper_bound(int mid, int n, vector<int>& a) {
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        // 对于 a[i]，找到第一个 > a[i] + mid 的元素的位置
        auto it = upper_bound(a.begin() + i + 1, a.end(), a[i] + mid);
        // 从 a[i+1] 到 it 之间的所有元素都满足差值小于等于 mid
        count += distance(a.begin() + i + 1, it);
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0;
    int right = a[n - 1] - a[0];
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        // if (count_le(mid, n, a) >= k) { // 两个check函数都可以
        if (count_le_upper_bound(mid, n, a) >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
