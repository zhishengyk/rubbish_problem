#include <iostream>

// Recursive function to calculate the combination C(m, n)
long long combinations(int m, int n) {
    // Base case: C(m, 0) is 1, not explicitly given but a standard base case.
    if (n == 0) {
        return 1;
    }
    // Base case: C(m, m) = 1. Can also be seen as C(m, n) where m=n.
    if (n == m) {
        return 1;
    }
    // Base case from problem: C(m, 1) = m
    if (n == 1) {
        return m;
    }
    // Recursive step using Pascal's identity
    return combinations(m - 1, n) + combinations(m - 1, n - 1);
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n;
    std::cin >> m >> n;

    // The problem statement gives C(m, 1) = m and C(m, m) = 1.
    // The main recurrence is C(m,n) = C(m-1,n) + C(m-1,n-1).
    // Let's verify the base cases required for this recurrence.
    // The recursion stops when n becomes 0 or n becomes equal to m.
    // C(m, 0) = 1 is a standard identity for combinations. Let's add it.

    long long result = combinations(m, n);

    std::cout << result << std::endl;

    return 0;
}
