#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <string>

using namespace std;

// 用于生成在 [min_val, max_val] 范围内的随机数
long long random_long(long long min_val, long long max_val) {
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> dist(min_val, max_val);
    return dist(rng);
}

void generate_data(int n_min, int n_max, long long k_min, long long k_max, long long time_max) {
    int n = random_long(n_min, n_max);
    long long k = random_long(k_min, k_max);
    cout << n << " " << k << endl;

    for (int i = 0; i < n; ++i) {
        long long start_time = random_long(0, time_max);
        long long duration = random_long(1, time_max / 10 > 0 ? time_max/10 : 1);
        long long end_time = start_time + duration;
        if (end_time > time_max) end_time = time_max;
        if (start_time >= end_time) start_time = end_time -1;

        cout << start_time << " " << end_time << endl;
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <subtask_id>" << endl;
        return 1;
    }

    int subtask_id = stoi(argv[1]);

    if (subtask_id >= 1 && subtask_id <= 5) {
        // Subtask 1: n and k are small
        generate_data(1, 20, 0, 100, 1000);
    } else if (subtask_id >= 6 && subtask_id <= 10) {
        // Subtask 2: k = 0
        generate_data(100, 1000, 0, 0, 1e9);
    } else if (subtask_id >= 11 && subtask_id <= 15) {
        // Subtask 3: Small time range
        generate_data(1000, 10000, 1, 1000, 50000);
    } else if (subtask_id >= 16 && subtask_id <= 20) {
        // Subtask 4: Large random data
        generate_data(90000, 100000, 0, 1e9, 1e9);
    } else {
        cerr << "Invalid subtask_id" << endl;
        return 1;
    }

    return 0;
}
