#include <iostream>

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // The problem asks for the number of ways to arrange colored ribbons of length n.
    // Let w(i) be the number of valid sequences of length i ending with White.
    // Let r(i) be the number of valid sequences of length i ending with Red.
    // A blue ribbon cannot be at the end, as it must be between a white and a red one.
    //
    // Recurrence relations:
    // A sequence ending in White at position i must have Red or Blue at i-1.
    // - If preceded by Red: The number of ways is r(i-1).
    // - If preceded by Blue: The sequence is ...R-B-W, so the number of ways is r(i-2).
    // So, w(i) = r(i-1) + r(i-2).
    // By symmetry, r(i) = w(i-1) + w(i-2).
    //
    // Base cases:
    // For n=1: "W", "R". So w(1)=1, r(1)=1.
    // For n=2: "WR", "RW". So w(2)=1, r(2)=1.
    //
    // Since w(1)=r(1) and w(2)=r(2), it follows that w(i) = r(i) for all i >= 1.
    // Let F(i) = w(i) = r(i).
    // The recurrence becomes F(i) = F(i-1) + F(i-2), which is the Fibonacci sequence.
    // We define F(1)=1, F(2)=1.
    //
    // The total number of solutions for length n is w(n) + r(n) = 2 * F(n).

    if (n == 1) { // Although problem constraints say n >= 2
        std::cout << 2 << std::endl;
        return 0;
    }

    long long f_prev = 1; // Represents F_{i-1}, starting with F_1=1
    long long f_curr = 1; // Represents F_i, starting with F_2=1

    // Loop to calculate F_n iteratively
    for (int i = 3; i <= n; ++i) {
        long long f_next = f_prev + f_curr;
        f_prev = f_curr;
        f_curr = f_next;
    }

    // The result is 2 * F_n
    std::cout << 2 * f_curr << std::endl;

    return 0;
}
