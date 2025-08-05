#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// Structure to hold the coordinates of a point
struct Point {
    int x, y;
};

// Function to calculate the Manhattan distance between two points
long long manhattan_distance(Point p1, Point p2) {
    return std::abs(static_cast<long long>(p1.x) - p2.x) + std::abs(static_cast<long long>(p1.y) - p2.y);
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    // Calculate the total distance without skipping any point
    long long total_distance = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_distance += manhattan_distance(points[i], points[i + 1]);
    }

    long long min_total_distance = LLONG_MAX;

    // Iterate through each intermediate point to consider skipping it
    // We cannot skip the first (index 0) or the last (index n-1) point
    for (int i = 1; i < n - 1; ++i) {
        // The original path segment is points[i-1] -> points[i] -> points[i+1]
        long long original_segment_dist = manhattan_distance(points[i-1], points[i]) + manhattan_distance(points[i], points[i+1]);
        
        // The new path segment after skipping points[i] is points[i-1] -> points[i+1]
        long long new_segment_dist = manhattan_distance(points[i-1], points[i+1]);
        
        // Calculate the new total distance by adjusting the original total distance
        long long current_total_distance = total_distance - original_segment_dist + new_segment_dist;
        
        // Update the minimum total distance found so far
        if (current_total_distance < min_total_distance) {
            min_total_distance = current_total_distance;
        }
    }

    std::cout << min_total_distance << std::endl;

    return 0;
}
