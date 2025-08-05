#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

struct Person {
    int id;
    int time;
};

bool comparePeople(const Person& a, const Person& b) {
    return a.time < b.time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        people[i].id = i + 1;
        std::cin >> people[i].time;
    }

    std::sort(people.begin(), people.end(), comparePeople);

    double total_wait_time = 0;
    double current_time = 0;
    for (int i = 0; i < n; ++i) {
        total_wait_time += current_time;
        current_time += people[i].time;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << people[i].id << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2) << total_wait_time / n << std::endl;

    return 0;
}
