#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stack<char> s;
    for (char c : line) {
        if (c == '#') {
            if (!s.empty()) {
                s.pop();
            }
        } else if (c == '@') {
            while (!s.empty()) {
                s.pop();
            }
        } else {
            s.push(c);
        }
    }

    std::vector<char> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    std::reverse(result.begin(), result.end());

    for (char c : result) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
