#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void solve_case() {
    int n;
    std::cin >> n;
    
    std::list<int> session_list;

    for (int i = 0; i < n; ++i) {
        int id;
        std::cin >> id;
        
        // If the id exists, remove it.
        session_list.remove(id);
        
        // Add the new id to the front.
        session_list.push_front(id);
    }

    bool first = true;
    for (int id : session_list) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << id;
        first = false;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve_case();
    }
    
    return 0;
}
