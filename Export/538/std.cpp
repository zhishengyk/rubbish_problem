#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line, '@');

    std::stringstream ss(line);
    std::string token;
    std::stack<long long> s;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            long long b = s.top(); s.pop();
            long long a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        } else {
            s.push(stoll(token));
        }
    }

    std::cout << s.top() << std::endl;

    return 0;
}
