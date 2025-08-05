#include <iostream>
#include <vector>

const int MOD = 32767;

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Since k can be up to 1,000,000 and we have multiple test cases,
    // it's efficient to pre-calculate the Pell sequence up to the maximum possible k.
    // However, a simpler approach for typical competitive programming scenarios
    // where max k isn't excessively large across all test cases is to compute on the fly.
    // Given k < 1,000,000, pre-calculation is better if max_k is hit frequently.
    // Let's stick to on-the-fly calculation per test case as it's simpler to implement
    // and might be sufficient if max k is not always large.
    // The problem statement implies k can be different for each test case.
    // Let's find the max k among all test cases and compute up to that.
    
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

    std::vector<int> pell(max_k + 1);

    if (max_k >= 1) pell[1] = 1;
    if (max_k >= 2) pell[2] = 2;

    for (int i = 3; i <= max_k; ++i) {
        pell[i] = (2 * pell[i - 1] + pell[i - 2]) % MOD;
    }

    for (int k : k_values) {
        std::cout << pell[k] << std::endl;
    }

    return 0;
}
