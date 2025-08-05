#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<tuple<int, int, int>> solutions;

    do {
        long long num1 = p[0] * 100 + p[1] * 10 + p[2];
        long long num2 = p[3] * 100 + p[4] * 10 + p[5];
        long long num3 = p[6] * 100 + p[7] * 10 + p[8];

        if (num1 * b == num2 * a && num1 * c == num3 * a) {
            solutions.emplace_back(num1, num2, num3);
        }
    } while (next_permutation(p.begin(), p.end()));

    if (solutions.empty()) {
        cout << "No!!!" << endl;
    } else {
        sort(solutions.begin(), solutions.end());
        for (const auto& sol : solutions) {
            cout << get<0>(sol) << " " << get<1>(sol) << " " << get<2>(sol) << endl;
        }
    }

    return 0;
}
