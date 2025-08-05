#include <iostream>

long long getNext(long long n) {
    // c1: Isolate the rightmost 1
    long long c1 = n & -n;
    // c2: Create a larger number by flipping the rightmost 0 that has 1s to its right
    long long c2 = n + c1;
    // c3: Create a mask of the 1s that were moved, then shift them to the rightmost positions
    long long c3 = (((n ^ c2) / c1) >> 2);
    // Combine the larger prefix with the moved 1s
    return c2 | c3;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    while (std::cin >> n && n != 0) {
        std::cout << getNext(n) << std::endl;
    }
    return 0;
}
