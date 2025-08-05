#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

struct SolutionState {
    double total_v;
    double total_s;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double v0, c0;
    std::cin >> v0 >> c0;

    int n;
    std::cin >> n;

    std::stack<SolutionState> history;
    SolutionState current_state = {v0, v0 * c0 / 100.0};

    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;

        if (op == 'P') {
            double v, c;
            std::cin >> v >> c;
            history.push(current_state);
            current_state.total_v += v;
            current_state.total_s += v * c / 100.0;
        } else if (op == 'Z') {
            if (!history.empty()) {
                current_state = history.top();
                history.pop();
            }
        }

        double concentration = (current_state.total_v == 0) ? 0 : (current_state.total_s / current_state.total_v * 100.0);
        std::cout << std::fixed << std::setprecision(0) << current_state.total_v << " "
                  << std::fixed << std::setprecision(5) << concentration << std::endl;
    }

    return 0;
}
