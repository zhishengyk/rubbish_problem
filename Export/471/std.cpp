#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }

    long long avg = sum / n;
    int moves = 0;

    for (int i = 0; i < n; ++i) {
        a[i] -= avg;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != 0) {
            moves++;
            a[i+1] += a[i];
        }
    }
    
    std::cout << moves << std::endl;

    return 0;
}
