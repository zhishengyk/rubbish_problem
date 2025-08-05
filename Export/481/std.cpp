#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;

    for (int i = 1; i <= M / 2; ++i) {
        int sum = 0;
        for (int j = i; j < M; ++j) {
            sum += j;
            if (sum == M) {
                if (j > i) {
                    std::cout << i << " " << j << std::endl;
                }
                break;
            }
            if (sum > M) {
                break;
            }
        }
    }

    return 0;
}
