#include <iostream>
#include <vector>
#include <list>
#include <iterator>

void solve() {
    int n;
    std::cin >> n;

    std::list<int> queue;
    std::vector<std::list<int>::iterator> positions(n + 1);
    std::vector<bool> in_queue(n + 1, false);

    // 1号同学入列
    queue.push_back(1);
    positions[1] = queue.begin();
    in_queue[1] = true;

    // 2~N号同学入列
    for (int i = 2; i <= n; ++i) {
        int k, p;
        std::cin >> k >> p;
        if (p == 0) { // 左边
            positions[i] = queue.insert(positions[k], i);
        } else { // 右边
            positions[i] = queue.insert(std::next(positions[k]), i);
        }
        in_queue[i] = true;
    }

    // 去掉M个同学
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        if (in_queue[x]) {
            queue.erase(positions[x]);
            in_queue[x] = false;
        }
    }

    // 输出队列
    bool first = true;
    for (int student : queue) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << student;
        first = false;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
