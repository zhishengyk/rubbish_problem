#include <iostream>

// Function to calculate the initial number of bowls
long long calculate_initial_bowls(int n) {
    long long bowls = 1; // Start with the number of bowls on day n

    // Loop backward from day n-1 down to day 1
    for (int day = n - 1; day >= 1; --day) {
        bowls = (bowls + 1) * 2;
    }
    return bowls;
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // Read multiple test cases until end of input
    while (std::cin >> n) {
        if (n > 1 && n < 30) {
            std::cout << calculate_initial_bowls(n) << std::endl;
        }
    }

    return 0;
}
