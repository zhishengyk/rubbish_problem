#include <iostream>
#include <vector>

const int MOD = 10007;
const int MAX_K = 1000;

// 组合数表
int C[MAX_K + 1][MAX_K + 1];

// 预处理组合数 (杨辉三角)
void precompute_combinations() {
    for (int i = 0; i <= MAX_K; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

// 快速幂函数
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 预处理
    precompute_combinations();

    long long a, b, k, n, m;
    std::cin >> a >> b >> k >> n >> m;

    // 计算 a^n
    long long term1 = power(a, n);
    
    // 计算 b^m
    long long term2 = power(b, m);

    // 查找 C(k, n)
    long long term3 = C[k][n];

    // 计算最终结果
    long long result = (term1 * term2) % MOD;
    result = (result * term3) % MOD;

    std::cout << result << std::endl;

    return 0;
}
