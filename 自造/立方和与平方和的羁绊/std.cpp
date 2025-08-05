#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

// This function checks if a number n can be expressed as the sum of squares
// and sum of cubes of three integers a, b, c.
bool can_be_represented(int n) {
    // If n is negative, the sum of squares a^2 + b^2 + c^2 = n is impossible
    // for real integers a, b, c, since squares are always non-negative.
    if (n < 0) {
        return false;
    }

    // The search space for a, b, and c can be constrained.
    // Since a^2 <= n, |a| <= sqrt(n).
    // Given n < 300, sqrt(n) is approximately 17.3.
    // So, we can set our search limit slightly above that.
    int limit = static_cast<int>(sqrt(n)) + 2;

    // We iterate through possible values for a, b, and c.
    // To optimize, we can assume a <= b <= c to avoid redundant permutations.
    for (int a = -limit; a <= limit; ++a) {
        for (int b = a; b <= limit; ++b) {
            // Early exit optimization: if a^2 + b^2 already exceeds n,
            // no non-negative c^2 can satisfy the equation.
            if (a * a + b * b > n) {
                // Since b is increasing, further iterations for b won't help either if a is fixed.
                // However, a could be negative, so we can't break from the outer loop yet.
                continue;
            }
            for (int c = b; c <= limit; ++c) {
                // Check if the sum of squares matches n
                if (a * a + b * b + c * c == n) {
                    // If it matches, check if the sum of cubes also matches n
                    if (a * a * a + b * b * b + c * c == n) {
                        return true; // Found a valid triplet (a, b, c)
                    }
                }
                // Further optimization: if the sum of squares exceeds n,
                // increasing c will only make it larger, so we can break the inner loop.
                if (a * a + b * b + c * c > n) {
                    break;
                }
            }
        }
    }

    // If no such triplet is found after checking all combinations
    return false;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        if (can_be_represented(n)) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}
