#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> a >> b >> c >> d;

    std::vector<double> roots;

    for (int i = -100; i < 100 && roots.size() < 3; ++i) {
        double left = i;
        double right = i + 1;
        double f_left = f(left);
        double f_right = f(right);

        if (std::abs(f_left) < 1e-9) { // Root is exactly at integer
             // Check if already found to handle cases where interval search finds it twice
            bool found = false;
            for(double r : roots) {
                if(std::abs(r - left) < 1e-3) {
                    found = true;
                    break;
                }
            }
            if (!found) roots.push_back(left);
        }
        
        if (f_left * f_right < 0) { // Root is within (left, right)
            for (int j = 0; j < 100; ++j) {
                double mid = (left + right) / 2;
                if (f(mid) * f_left > 0) { // Same sign as left
                    left = mid;
                } else {
                    right = mid;
                }
            }
            roots.push_back(left);
        }
    }
    
    // Check for root at 100
    if (roots.size() < 3 && std::abs(f(100.0)) < 1e-9) {
        roots.push_back(100.0);
    }


    for (size_t i = 0; i < roots.size(); ++i) {
        std::cout << std::fixed << std::setprecision(2) << roots[i] << (i == roots.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
