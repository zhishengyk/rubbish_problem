#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <sstream>

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to apply an operator to two operands
long long applyOp(long long a, long long b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Function to evaluate a postfix expression
long long evaluatePostfix(const std::string& postfix) {
    std::stack<long long> values;
    std::stringstream ss(postfix);
    std::string token;
    while (ss >> token) {
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1]))) {
            values.push(stoll(token));
        } else {
            long long val2 = values.top();
            values.pop();
            long long val1 = values.top();
            values.pop();
            values.push(applyOp(val1, val2, token[0]));
        }
    }
    return values.top();
}

// Function to convert infix to postfix
std::string infixToPostfix(std::string infix) {
    std::stack<char> ops;
    std::stringstream postfix;
    std::map<char, int> prec;
    prec['+'] = 1; prec['-'] = 1;
    prec['*'] = 2; prec['/'] = 2;

    for (int i = 0; i < infix.length(); ++i) {
        if (isspace(infix[i])) continue;

        if (isdigit(infix[i])) {
            long long num = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                postfix << infix[i];
                i++;
            }
            i--;
            postfix << " ";
        } else if (infix[i] == '(') {
            ops.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix << ops.top() << " ";
                ops.pop();
            }
            if (!ops.empty()) ops.pop();
        } else { // An operator
             if ((infix[i] == '-' || infix[i] == '+') && (i == 0 || infix[i-1] == '(' || !isdigit(infix[i-1])) ) {
                // Unary operator, treat as part of number
                if (isdigit(infix[i+1])) {
                    postfix << infix[i];
                    continue;
                }
             }

            while (!ops.empty() && ops.top() != '(' && prec[ops.top()] >= prec[infix[i]]) {
                postfix << ops.top() << " ";
                ops.pop();
            }
            ops.push(infix[i]);
        }
    }

    while (!ops.empty()) {
        postfix << ops.top() << " ";
        ops.pop();
    }

    return postfix.str();
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string line;
    std::getline(std::cin, line, '@');

    // A simple validation
    std::stack<char> parens;
    bool last_is_op = true;
    for(int i = 0; i < line.length(); ++i) {
        if(line[i] == '(') parens.push('(');
        else if(line[i] == ')') {
            if(parens.empty()) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            parens.pop();
        }
        if(std::string("+-*/").find(line[i]) != std::string::npos){
            if(last_is_op && (i > 0 && line[i-1] != ')')){
                 if(line[i] == '*' || line[i] == '/'){
                    std::cout << "NO" << std::endl;
                    return 0;
                 }
                 continue; // unary sign
            }
            last_is_op = true;
        } else if(isdigit(line[i])) {
            last_is_op = false;
        }
    }
    if(!parens.empty()) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::string postfix = infixToPostfix(line);
    std::cout << evaluatePostfix(postfix) << std::endl;

    return 0;
}
