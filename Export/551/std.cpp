#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>

// DSU data structure
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(3, std::vector<int>(n));
    std::vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[0][i];
        pos[a[0][i]] = i;
    }
    for (int i = 0; i < n; ++i) std::cin >> a[1][i];
    for (int i = 0; i < n; ++i) std::cin >> a[2][i];

    std::vector<int> b_map(n + 1), c_map(n + 1);
    for (int i = 1; i <= n; ++i) {
        b_map[i] = a[1][pos[i]];
        c_map[i] = a[2][pos[i]];
    }

    // A number can be kept only if it's part of a cycle in BOTH b_map and c_map views.
    // Let's find nodes that are part of a cycle in their respective graphs.
    auto get_cycle_nodes = [&](const std::vector<int>& graph) {
        std::set<int> cycle_nodes;
        std::vector<int> visited(n + 1, 0); // 0: unvisited, 1: visiting, 2: visited
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 0) {
                std::vector<int> path;
                int curr = i;
                while (visited[curr] == 0) {
                    visited[curr] = 1;
                    path.push_back(curr);
                    curr = graph[curr];
                }

                if (visited[curr] == 1) { // Cycle detected
                    bool in_cycle = false;
                    for (int node : path) {
                        if (node == curr) in_cycle = true;
                        if (in_cycle) {
                            cycle_nodes.insert(node);
                        }
                    }
                }
                for(int node : path) {
                    visited[node] = 2;
                }
            }
        }
        return cycle_nodes;
    };

    std::set<int> b_cycle_nodes = get_cycle_nodes(b_map);
    std::set<int> c_cycle_nodes = get_cycle_nodes(c_map);

    std::set<int> relevant_nodes;
    std::set_intersection(b_cycle_nodes.begin(), b_cycle_nodes.end(),
                          c_cycle_nodes.begin(), c_cycle_nodes.end(),
                          std::inserter(relevant_nodes, relevant_nodes.begin()));

    DSU dsu(n);
    for (int node : relevant_nodes) {
        dsu.unite(node, b_map[node]);
        dsu.unite(node, c_map[node]);
    }
    
    std::map<int, std::set<int>> components;
    for (int node : relevant_nodes) {
        components[dsu.find(node)].insert(node);
    }

    int kept_count = 0;
    for (auto const& [root, component_nodes] : components) {
        bool ok = true;
        for (int node : component_nodes) {
            if (component_nodes.find(b_map[node]) == component_nodes.end() ||
                component_nodes.find(c_map[node]) == component_nodes.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            kept_count += component_nodes.size();
        }
    }

    std::cout << n - kept_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
