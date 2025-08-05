#include <iostream>
#include <vector>
#include <random>
#include <chrono>

long long rand_long(long long l, long long r) {
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main() {
    int n = rand_long(1, 10);
    long long L = rand_long(1, n);
    long long R = rand_long(L, n);
    std::cout << n << " " << L << " " << R << std::endl;

    for (int i = 0; i < n; ++i) {
        long long T_i = rand_long(1, 2000);
        long long M_i = rand_long(1, 512);
        std::cout << T_i << " " << M_i << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        long long t_i = rand_long(1, 1000);
        long long m_i = rand_long(1, 256);
        std::cout << t_i << " " << m_i << std::endl;
    }

    return 0;
}
