#include <iostream>
#include <vector>

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Let dp[i] be the total number of cows at the beginning of year i.
    // The number of new cows born at the beginning of year i is equal to
    // the number of cows that are at least 3 years old.
    // A cow born in year j becomes 1 year old in year j+1, 2 in j+2, 3 in j+3.
    // It starts giving birth in year j+3.
    // The original cow (born in year 0) gives birth from year 2 onwards.
    // Let's analyze the number of cows year by year:
    // Year 1: 1 (original)
    // Year 2: 2 (original + 1 newborn from original)
    // Year 3: 3 (original + 2 newborns from original)
    // Year 4: 4 (original + 3 from original + 1 from the cow born in year 2)
    //
    // The number of new cows in year i is the number of cows that were alive in year i-2.
    // This is not quite right. A cow born in year j starts giving birth in year j+3.
    // Let C(i) be the number of cows in year i.
    // C(i) = C(i-1) + (Number of cows that give birth in year i)
    // A cow gives birth from its 4th year onwards. A cow born at the start of year Y will be 3 years old at the start of year Y+3, and will give birth at the start of year Y+4.
    // This is confusing. Let's re-read: "每头小母牛从第四个年头开始".
    // Year 1: Born. Age 0.
    // Year 2: Age 1.
    // Year 3: Age 2.
    // Year 4: Age 3. "第四个年头" -> gives birth.
    // So, a cow born in year Y gives birth in years Y+3, Y+4, ...
    // The original cow was there before year 1. Let's assume it was born at time 0.
    // Year 1: Original. Total: 1.
    // Year 2: Original + baby1 (from original). Total: 2.
    // Year 3: Original + baby1 + baby2 (from original). Total: 3.
    // Year 4: Original + baby1 + baby2 + baby3 (from original) + baby4 (from baby1). Total: 4.
    // Year 5: Original + ... + baby5(from baby1) + baby6(from baby2). Total: 6.
    //
    // Let f(i) be the number of cows in year i.
    // f(i) = f(i-1) + (number of cows born in year i)
    // Number of cows born in year i = Number of cows that are at least 3 years old.
    // Number of cows that are at least 3 years old = Number of cows that existed in year i-3.
    // So, f(i) = f(i-1) + f(i-3) for i >= 4.
    
    std::vector<long long> dp(56);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;

    for (int i = 5; i <= 55; ++i) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }

    int n;
    while (std::cin >> n && n != 0) {
        std::cout << dp[n] << std::endl;
    }

    return 0;
}
