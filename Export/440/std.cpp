#include <iostream>
#include <cmath>
#include <iomanip>

// Function to calculate f(x, n)
double calculate_f(double x, double n) {
    return std::sqrt(n + x) + std::sqrt(n - x) + (x / std::sqrt(n));
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x, n;
    std::cin >> x >> n;
    
    // The problem description mentions specific values for players A and B,
    // but the input/output format suggests a general calculation.
    // Following the standard competitive programming practice of
    // solving for the given input.

    double result = calculate_f(x, n);

    // Output the result rounded to two decimal places
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;

    return 0;
}
