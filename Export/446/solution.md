## 问题446 题解

### 题目分析

本题是一个基础的编程问题，要求我们计算给定正整数 `n` 的阶乘。
阶乘的定义为： $n! = 1 \times 2 \times 3 \times \cdots \times n$。

输入是一个整数 `n`，范围是 $1 \leq n \leq 20$。

### 解题思路

计算阶乘最直接的方法是使用循环。我们可以初始化一个结果变量为1，然后用一个循环从1乘到 `n`。

#### 1. 数据类型选择

在开始编码前，需要考虑结果的可能大小。
-   $10! = 3,628,800$ (在32位 `int` 范围内)
-   $13! = 6,227,020,800$ (超出32位 `int` 范围，约 $2 \times 10^9$)
-   $20! \approx 2.43 \times 10^{18}$

由于 `n` 的最大值为20，`20!` 的结果非常大，会远远超过一个标准的32位整数（`int`）所能表示的最大值。因此，我们必须使用64位整数类型（在C++中是 `long long`）来存储阶乘的结果，以避免数据溢出。

#### 2. 算法实现

可以使用迭代或递归两种方式实现。

**a) 迭代法 (Iterative Approach)**

这是最高效、最简单的方法。

1.  定义一个 `long long` 类型的变量 `result` 并初始化为 `1`。
2.  使用一个 `for` 循环，从 `i = 1` 循环到 `n`。
3.  在循环内部，将 `result` 乘以 `i`：`result = result * i;`。
4.  循环结束后，`result` 中存储的就是 `n!` 的值。
5.  输出 `result`。

**b) 递归法 (Recursive Approach)**

虽然对于这个问题，迭代更优，但也可以用递归实现，因为阶乘有天然的递归结构：`n! = n * (n-1)!`。

1.  定义一个递归函数 `factorial(n)`。
2.  **基本情况**: 如果 `n` 是 `0` 或 `1`，函数返回 `1`。
3.  **递归步骤**: 否则，函数返回 `n * factorial(n-1)`。

对于本题的数据范围，两种方法都可以轻松解决。迭代法因其没有函数调用的开销而略快一些。

### C++ 迭代实现

```cpp
#include <iostream>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    std::cout << factorial(n) << std::endl;
    
    return 0;
}
```
