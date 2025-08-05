#include <iostream>

// Function to calculate factorial iteratively
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // The factorial of n can get very large.
    // 20! is 2,432,902,008,176,640,000 which fits within a 64-bit integer (long long).
    // The maximum value for a signed 64-bit integer is about 9 x 10^18.
    
    std::cout << factorial(n) << std::endl;

    return 0;
}
