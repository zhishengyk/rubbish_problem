#include <iostream>

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Let N(d) be the number of peaches at the beginning of day d.
    // The problem states that on day d, the monkey eats (N(d)/2 + 1) peaches.
    // So, the number of peaches left at the end of day d is N(d) - (N(d)/2 + 1) = N(d)/2 - 1.
    // This is also the number of peaches at the beginning of day d+1, so N(d+1) = N(d)/2 - 1.
    //
    // We can rearrange this to express N(d) in terms of N(d+1):
    // N(d) = (N(d+1) + 1) * 2.
    //
    // We are given that on the 10th day, there is only 1 peach left.
    // This means N(10) = 1.
    // We want to find N(1). We can work backward from day 9 to day 1.

    int peaches = 1; // Start with the number of peaches on day 10

    // Loop backward from day 9 to day 1
    for (int day = 9; day >= 1; --day) {
        peaches = (peaches + 1) * 2;
    }

    std::cout << peaches << std::endl;

    return 0;
}
