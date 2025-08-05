#include <iostream>
#include <string>
#include <stack>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string infix;
    std::cin >> infix;

    std::stack<char> ops;
    std::string postfix = "";
    std::map<char, int> prec;
    prec['+'] = 1;
    prec['-'] = 1;
    prec['*'] = 2;
    prec['/'] = 2;

    for (char c : infix) {
        if (isalpha(c)) {
            postfix += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); // Pop '('
        } else { // Operator
            while (!ops.empty() && ops.top() != '(' && prec[ops.top()] >= prec[c]) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }

    std::cout << postfix << std::endl;

    return 0;
}
