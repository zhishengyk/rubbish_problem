#include <bits/stdc++.h>
using namespace std;

/*
 数据分层
  - 子任务 1（tests 1-3）
      t = 1, n ≤ 100, |a_i| ≤ 1e3
  - 子任务 2（tests 4-7）
      t ≤ 50, Σn ≤ 5e3, |a_i| ≤ 1e5
  - 子任务 3（tests 8-10）
      满足原题最大范围：t ≤ 1e4, Σn ≤ 2e5, |a_i| ≤ 1e9
 */

static mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

long long randll(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main() {
    const int TOTAL_TESTS = 10;

    for (int tc = 1; tc <= TOTAL_TESTS; ++tc) {
        string inFile  = to_string(tc) + ".in";
        string outFile = to_string(tc) + ".out";

        ofstream fin(inFile);
        if (!fin) {
            cerr << "Cannot open " << inFile << endl;
            return 1;
        }

        if (tc <= 3) {
            // Subtask 1
            fin << 1 << "\n";
            int n = randll(1, 100);
            fin << n << "\n";
            for (int i = 0; i < n; ++i) {
                long long x = randll(-1000, 1000);
                fin << x << (i + 1 == n ? '\n' : ' ');
            }
        } else if (tc <= 7) {
            // Subtask 2
            int t = randll(1, 50);
            fin << t << "\n";
            int remaining = 5000;
            for (int k = 0; k < t; ++k) {
                int maxN = remaining - (t - k - 1); // leave at least 1 for each left case
                int n = randll(1, maxN);
                remaining -= n;
                fin << n << "\n";
                for (int i = 0; i < n; ++i) {
                    long long x = randll(-100000, 100000);
                    fin << x << (i + 1 == n ? '\n' : ' ');
                }
            }
        } else {
            // Subtask 3 (full constraints)
            int t = randll(1, 10000);
            fin << t << "\n";
            int remaining = 200000;
            for (int k = 0; k < t; ++k) {
                int maxN = remaining - (t - k - 1);
                int n = randll(1, maxN);
                remaining -= n;
                fin << n << "\n";
                for (int i = 0; i < n; ++i) {
                    long long x = randll(-1000000000LL, 1000000000LL);
                    fin << x << (i + 1 == n ? '\n' : ' ');
                }
            }
        }
        fin.close();

        // Run std solution to generate output files automatically
#ifdef _WIN32
        string cmd = ".\\std.exe < \"" + inFile + "\" > \"" + outFile + "\"";
#else
        string cmd = "./std < \"" + inFile + "\" > \"" + outFile + "\"";
#endif
        int ret = system(cmd.c_str());
        if (ret != 0) {
            cerr << "Command failed: " << cmd << endl;
            return 1;
        }
        cout << "Generated " << inFile << " & " << outFile << endl;
    }

    return 0;
}
