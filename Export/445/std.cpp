#include <iostream>
#include <vector>

const int MOD = 32767;

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    std::vector<int> k_values(n);
    int max_k = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> k_values[i];
        if (k_values[i] > max_k) {
            max_k = k_values[i];
        }
    }

    // Pre-calculate the Pell sequence up to the maximum k found in the input
    std::vector<int> pell(max_k + 1);

    if (max_k >= 1) pell[1] = 1;
    if (max_k >= 2) pell[2] = 2;

    for (int i = 3; i <= max_k; ++i) {
        pell[i] = (2 * pell[i - 1] + pell[i - 2]) % MOD;
    }

    // Output the pre-calculated results for each k
    for (int k : k_values) {
        std::cout << pell[k] << std::endl;
    }

    return 0;
}
