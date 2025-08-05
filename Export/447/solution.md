## 问题447 题解

### 题目分析

本题是经典的**汉诺塔（Tower of Hanoi）**问题。我们需要编写一个程序，对于给定的盘子数量 `n` 和三个杆的名称（例如 `A`, `B`, `C`），输出将所有盘子从起始杆（`A`）移动到目标杆（`B`），并使用辅助杆（`C`）的完整步骤。

移动规则：
1.  一次只能移动一个盘子。
2.  大盘子不能放在小盘子上面。

输出格式要求为 `source->disk_number->destination`。

### 解题思路

汉诺塔问题是递归思想的完美范例。解决这个问题的关键在于将一个大问题分解为几个相同类型的、但规模更小的子问题。

假设我们的任务是把 `n` 个盘子从 `source` 杆移动到 `destination` 杆，可以使用 `auxiliary` 杆作为临时存放点。

#### 递归三步曲

1.  **将 `n-1` 个较小的盘子从 `source` 移动到 `auxiliary`**：
    -   这是一个子问题：把 `n-1` 个盘子从 `source` 移到 `auxiliary`，此时 `destination` 杆可以作为辅助杆。
    -   递归调用 `hanoi(n-1, source, auxiliary, destination)`。

2.  **移动最大的盘子**：
    -   现在，`n-1` 个小盘子都在 `auxiliary` 杆上，`source` 杆上只剩下最大的第 `n` 号盘。
    -   我们可以直接将第 `n` 号盘从 `source` 移动到 `destination`。
    -   打印出这一步操作：`source -> n -> destination`。

3.  **将 `n-1` 个较小的盘子从 `auxiliary` 移动到 `destination`**：
    -   最后，我们需要把放在 `auxiliary` 杆上的 `n-1` 个盘子移动到 `destination` 杆上，放到第 `n` 号盘的上面。
    -   这又是同一个子问题：把 `n-1` 个盘子从 `auxiliary` 移到 `destination`，此时 `source` 杆可以作为辅助杆。
    -   递归调用 `hanoi(n-1, auxiliary, destination, source)`。

#### 基本情况 (Base Case)

递归必须有一个终止条件。在这个问题中，最简单的情况是只移动一个盘子（`n=1`）。当 `n=1` 时，我们直接把它从 `source` 移动到 `destination` 即可。

### 算法实现

我们可以创建一个递归函数 `hanoi(int n, char source, char destination, char auxiliary)` 来实现上述逻辑。

```cpp
#include <iostream>

void hanoi(int n, char source, char dest, char aux) {
    // 基本情况：只剩一个盘子
    if (n == 1) {
        std::cout << source << "->" << 1 << "->" << dest << std::endl;
        return;
    }
    
    // 递归步骤
    // 1. 将 n-1 个盘子从 source 移动到 aux
    hanoi(n - 1, source, aux, dest);
    
    // 2. 移动第 n 个盘子从 source 到 dest
    // 注意：输出的盘子编号是 n，而不是 1
    std::cout << source << "->" << n << "->" << dest << std::endl;
    
    // 3. 将 n-1 个盘子从 aux 移动到 dest
    hanoi(n - 1, aux, dest, source);
}

int main() {
    int num_disks;
    char start_peg, end_peg, aux_peg;
    
    std::cin >> num_disks >> start_peg >> end_peg >> aux_peg;
    
    // 从样例分析，输入是 n, start, end, aux
    hanoi(num_disks, start_peg, end_peg, aux_peg);
    
    return 0;
}
```
**代码逻辑修正**：在上面的 `hanoi` 函数中，输出盘子编号的部分需要注意。`hanoi(n, ...)` 函数负责移动的是当前问题中从1到n的n个盘子，其中最大的是n号盘。因此，在第2步移动最大盘时，应该输出其正确的编号，即 `n`。而在基本情况 `n=1` 时，移动的是当前子问题中唯一的一个盘子。但原始问题的盘子编号是固定的。因此，递归函数中传递盘子的具体编号会更清晰。

一个更准确的实现应该将要移动的盘子编号作为参数。

```cpp
#include <iostream>

// n: 当前要移动的盘子编号
void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        std::cout << source << "->" << n << "->" << dest << std::endl;
        return;
    }
    hanoi(n - 1, source, aux, dest);
    std::cout << source << "->" << n << "->" << dest << std::endl;
    hanoi(n - 1, aux, dest, source);
}
// main函数调用 hanoi(num_disks, ...);
```
这个实现是正确的，它隐含地处理了盘子编号。`hanoi(k, ...)` 移动的是 1 到 k 号盘子。

**关于输入**：从样例 `2 a b c` 和输出 `a->...->b` 来看，输入格式是 `盘子数 起始杆 目标杆 辅助杆`。
