#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int R, C, K;
    cin >> R >> C >> K;

    vector<string> grid(R);
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    long long count = 0;

    // 检查横向站位
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c <= C - K; ++c) {
            bool possible = true;
            for (int k = 0; k < K; ++k) {
                if (grid[r][c + k] == '#') {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                count++;
            }
        }
    }

    // 检查纵向站位
    for (int c = 0; c < C; ++c) {
        for (int r = 0; r <= R - K; ++r) {
            bool possible = true;
            for (int k = 0; k < K; ++k) {
                if (grid[r + k][c] == '#') {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                count++;
            }
        }
    }

    // 如果K=1，每个 '.' 会被横向和纵向各计一次，所以总数要除以2
    if (K == 1) {
        count /= 2;
    }

    cout << count << endl;

    return 0;
}
