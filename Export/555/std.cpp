#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <numeric>

const int BLOCK_SIZE = 320; // Approximately sqrt(100000)

std::vector<std::list<int>> blocks;

void rebuild() {
    std::vector<int> all_elements;
    for (const auto& block : blocks) {
        all_elements.insert(all_elements.end(), block.begin(), block.end());
    }
    blocks.clear();
    for (size_t i = 0; i < all_elements.size(); ++i) {
        if (i % BLOCK_SIZE == 0) {
            blocks.push_back({});
        }
        blocks.back().push_back(all_elements[i]);
    }
    if (blocks.empty()) { // Handle case where all elements are deleted
        blocks.push_back({});
    }
}

void insert_val(int x, int y) {
    if (x == 0) {
        blocks.front().push_front(y);
        if (blocks.front().size() > 2 * BLOCK_SIZE) rebuild();
        return;
    }

    int current_pos = 0;
    for (auto& block : blocks) {
        if (current_pos + block.size() >= x) {
            int inner_idx = x - current_pos -1;
            auto it = block.begin();
            std::advance(it, inner_idx);
            it++; // after the x-th element
            block.insert(it, y);
            if (block.size() > 2 * BLOCK_SIZE) rebuild();
            return;
        }
        current_pos += block.size();
    }
}

void delete_val(int x) {
    int current_pos = 0;
    for (auto& block : blocks) {
        if (current_pos + block.size() >= x) {
            int inner_idx = x - current_pos - 1;
            auto it = block.begin();
            std::advance(it, inner_idx);
            block.erase(it);
             if (block.empty() && blocks.size() > 1) {
                // This check is simple, but a full rebuild is safer
                // to avoid many empty blocks. For simplicity, we can 
                // just rely on the periodic rebuild triggered by insertion.
            }
            return;
        }
        current_pos += block.size();
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i % BLOCK_SIZE == 0) {
            blocks.push_back({});
        }
        blocks.back().push_back(a[i]);
    }
     if (blocks.empty()) {
        blocks.push_back({});
    }


    for (int k = 0; k < m; ++k) {
        int opt, x, y;
        std::cin >> opt;
        if (opt == 1) {
            std::cin >> x >> y;
            insert_val(x, y);
        } else {
            std::cin >> x;
            delete_val(x);
        }
    }

    bool first = true;
    for (const auto& block : blocks) {
        for (int val : block) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << val;
            first = false;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
