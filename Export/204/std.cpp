#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, l, r;
    std::cin >> n >> l >> r;

    long long l_div_n = l / n;
    long long r_div_n = r / n;

    if (l_div_n < r_div_n) {
        // 区间跨越了n的倍数，或者区间长度大于等于n
        // 这保证了区间内一定存在一个数 k，使得 k % n == n - 1
        std::cout << n - 1 << std::endl;
    } else {
        // l 和 r 在同一个模周期内
        // k从l到r，k%n是单调递增的
        // 所以最大值在k=r时取得
        std::cout << r % n << std::endl;
    }

    return 0;
}
