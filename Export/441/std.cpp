#include <iostream>
#include <iomanip>

// Recursive function to calculate the Hermite polynomial H_n(x)
double hermite(int n, double x) {
    // Base case: n = 0
    if (n == 0) {
        return 1.0;
    }
    // Base case: n = 1
    if (n == 1) {
        return 2.0 * x;
    }
    // Recursive step: n > 1
    return 2.0 * x * hermite(n - 1, x) - 2.0 * (n - 1) * hermite(n - 2, x);
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    double x; // x can be a non-integer, so use double
    std::cin >> n >> x;

    double result = hermite(n, x);

    // Output the result rounded to two decimal places
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;

    return 0;
}
