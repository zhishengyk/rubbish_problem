#include <iostream>

/**
 * @brief Recursively finds and prints the prime factors of a number.
 * 
 * @param n The number to factorize.
 * @param divisor The current divisor to test, starting from 2.
 */
void find_prime_factors(int n, int divisor) {
    // Base case: If n is 1, we are done with factorization.
    if (n == 1) {
        return;
    }

    // If the divisor is greater than the square root of n,
    // then the remaining n must be a prime factor itself.
    if (divisor * divisor > n) {
        std::cout << n << " ";
        return;
    }

    // If the current divisor divides n
    if (n % divisor == 0) {
        // Print the divisor
        std::cout << divisor << " ";
        // Recursively factorize the remaining part (n / divisor)
        // starting again with the same divisor, as it might appear multiple times.
        find_prime_factors(n / divisor, divisor);
    } else {
        // If the current divisor does not divide n, try the next divisor.
        find_prime_factors(n, divisor + 1);
    }
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    find_prime_factors(n, 2);
    std::cout << std::endl;

    return 0;
}
