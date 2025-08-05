#include <iostream>
#include <string>

/**
 * @brief Solves the Tower of Hanoi problem recursively.
 * 
 * @param n The number of disks to move.
 * @param source The source peg.
 * @param destination The destination peg.
 * @param auxiliary The auxiliary peg.
 */
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there is only one disk, move it directly.
    if (n == 1) {
        std::cout << source << "->" << n << "->" << destination << std::endl;
        return;
    }

    // 1. Move n-1 disks from the source peg to the auxiliary peg,
    //    using the destination peg as the auxiliary.
    tower_of_hanoi(n - 1, source, auxiliary, destination);

    // 2. Move the nth disk (the largest) from the source to the destination peg.
    std::cout << source << "->" << n << "->" << destination << std::endl;

    // 3. Move the n-1 disks from the auxiliary peg to the destination peg,
    //    using the source peg as the auxiliary.
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    // Improve I/O performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    char source, destination, auxiliary;
    // The problem states "three single character strings", but reading into chars is more direct.
    std::cin >> n >> source >> destination >> auxiliary;
    
    // Let's reinterpret the input based on the Tower of Hanoi logic.
    // The goal is typically to move from a source to a destination.
    // Let the three chars be source, auxiliary, and destination pegs.
    // The sample output suggests moving from 'a' to 'b' via 'c'.
    // Let's adjust the call. The problem wants to move from the first peg to the *middle* peg.
    // In the sample, `a b c`, it moves from `a` to `b` using `c`.
    // Wait, the sample `2 a b c` moves `a->1->c`, `a->2->b`, `c->1->b`.
    // This moves the tower from A to B. So `source` is a, `destination` is b, `aux` is c.
    // But the problem description says "全部移到中间的杆上" (move all to the middle rod).
    // Let's stick to the standard interpretation: move N disks from a source peg to a destination peg.
    // Let the input be N, source, auxiliary, destination.
    
    // The sample `2 a b c` has pegs `a`, `b`, `c`. 
    // It's ambiguous if the goal is to move a->b or a->c.
    // Let's re-read the sample output trace:
    // a->1->c  (Move disk 1 from a to c)
    // a->2->b  (Move disk 2 from a to b)
    // c->1->b  (Move disk 1 from c to b)
    // Final state: Disks 1 and 2 are on peg b. The tower has been moved from a to b.
    // So the input `2 a b c` means: move 2 disks from `a` to `b` using `c` as auxiliary.
    // It seems the second character is the DESTINATION and the third is the AUXILIARY.

    char actual_source = source;
    char actual_destination = destination;
    char actual_auxiliary = auxiliary;

    tower_of_hanoi(n, actual_source, actual_destination, actual_auxiliary);

    return 0;
}
