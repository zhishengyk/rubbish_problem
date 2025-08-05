#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void solve() {
    ifstream fin("tmp.in");
    ofstream fout("tmp.out");

    const int MAX_R = 1000000;
    vector<long long> factor_sum(MAX_R + 1, 0);
    vector<int> abundant_prefix_sum(MAX_R + 1, 0);

    for (int i = 1; i <= MAX_R; ++i) {
        for (int j = i; j <= MAX_R; j += i) {
            factor_sum[j] += i;
        }
    }

    abundant_prefix_sum[0] = 0;
    for (int i = 1; i <= MAX_R; ++i) {
        abundant_prefix_sum[i] = abundant_prefix_sum[i - 1];
        if (factor_sum[i] >= 2LL * i) {
            abundant_prefix_sum[i]++;
        }
    }

    int n;
    fin >> n;
    while (n--) {
        int l, r;
        fin >> l >> r;
        fout << abundant_prefix_sum[r] - abundant_prefix_sum[l - 1] << "\n";
    }

    fin.close();
    fout.close();
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    // We will generate 20 test cases in total.
    // Subtask 1: tests 1-6
    // Subtask 2: tests 7-12
    // Subtask 3: tests 13-20
    for (int test = 1; test <= 20; ++test) {
        string in_file = to_string(test) + ".in";
        string out_file = to_string(test) + ".out";

        ofstream fin(in_file);

        int n;
        if (test <= 6) { // Subtask 1: 1 <= n <= 100, 1 <= r <= 1000
            n = uniform_int_distribution<>(90, 100)(gen);
            if (test == 1) n = 1;
            if (test == 2) n = 100;
            fin << n << "\n";
            for (int i = 0; i < n; ++i) {
                int l = uniform_int_distribution<>(1, 900)(gen);
                int r = uniform_int_distribution<>(l, 1000)(gen);
                if (test == 1) { l = 1; r = 1; }
                if (test == 2) { l = 999; r = 1000; }
                fin << l << " " << r << "\n";
            }
        } else if (test <= 12) { // Subtask 2: 1 <= n <= 10000, 1 <= r <= 100000
            n = uniform_int_distribution<>(9000, 10000)(gen);
            if (test == 7) n = 1;
            if (test == 8) n = 10000;
            fin << n << "\n";
            for (int i = 0; i < n; ++i) {
                int l = uniform_int_distribution<>(1, 90000)(gen);
                int r = uniform_int_distribution<>(l, 100000)(gen);
                 if (test == 7) { l = 1; r = 100000; }
                fin << l << " " << r << "\n";
            }
        } else { // Subtask 3: 1 <= n <= 2*10^5, 1 <= r <= 10^6
             n = uniform_int_distribution<>(190000, 200000)(gen);
             if (test == 13) n = 1;
             if (test == 20) n = 200000;
             fin << n << "\n";
             for (int i = 0; i < n; ++i) {
                int l, r;
                if (i == 0 || test == 13) { // Edge case: full range
                    l = 1, r = 1000000;
                } else if (i % 5 == 1) { // Edge case: small range
                    l = uniform_int_distribution<>(1, 1000000)(gen);
                    r = min(l + uniform_int_distribution<>(0, 10)(gen), 1000000);
                } else if (i % 5 == 2) { // Edge case: large l
                     l = uniform_int_distribution<>(999000, 1000000)(gen);
                     r = 1000000;
                } else { // Random cases
                    l = uniform_int_distribution<>(1, 999999)(gen);
                    r = uniform_int_distribution<>(l, 1000000)(gen);
                }
                 fin << l << " " << r << "\n";
             }
        }

        fin.close();

        // Generate output by calling std
        ofstream temp_in("tmp.in");
        ifstream current_in(in_file);
        temp_in << current_in.rdbuf();
        temp_in.close();
        current_in.close();
        
        solve();

        rename("tmp.out", out_file.c_str());
        remove("tmp.in");

        cout << "Generated test " << test << endl;
    }

    return 0;
}
