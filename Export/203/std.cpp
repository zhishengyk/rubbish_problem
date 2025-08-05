#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int r, int c, int n) {
    return r >= 1 && r <= n && c >= 1 && c <= n;
}

void light_up_torch(vector<vector<bool>>& lit_map, int r, int c, int n) {
    // Center
    if (is_valid(r, c, n)) lit_map[r][c] = true;

    // Distance 1
    if (is_valid(r + 1, c, n)) lit_map[r + 1][c] = true;
    if (is_valid(r - 1, c, n)) lit_map[r - 1][c] = true;
    if (is_valid(r, c + 1, n)) lit_map[r][c + 1] = true;
    if (is_valid(r, c - 1, n)) lit_map[r][c - 1] = true;

    // Distance 2
    if (is_valid(r + 2, c, n)) lit_map[r + 2][c] = true;
    if (is_valid(r - 2, c, n)) lit_map[r - 2][c] = true;
    if (is_valid(r, c + 2, n)) lit_map[r][c + 2] = true;
    if (is_valid(r, c - 2, n)) lit_map[r][c - 2] = true;
    
    // Diagonal
    if (is_valid(r + 1, c + 1, n)) lit_map[r + 1][c + 1] = true;
    if (is_valid(r + 1, c - 1, n)) lit_map[r + 1][c - 1] = true;
    if (is_valid(r - 1, c + 1, n)) lit_map[r - 1][c + 1] = true;
    if (is_valid(r - 1, c - 1, n)) lit_map[r - 1][c - 1] = true;
}

void light_up_glowstone(vector<vector<bool>>& lit_map, int r, int c, int n) {
    for (int i = r - 2; i <= r + 2; ++i) {
        for (int j = c - 2; j <= c + 2; ++j) {
            if (is_valid(i, j, n)) {
                lit_map[i][j] = true;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> lit_map(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        light_up_torch(lit_map, r, c, n);
    }

    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        light_up_glowstone(lit_map, r, c, n);
    }

    int monster_count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!lit_map[i][j]) {
                monster_count++;
            }
        }
    }

    cout << monster_count << endl;

    return 0;
}
