## 问题441 题解

### 题目分析

本题要求我们根据给定的递归公式，计算 Hermite（埃尔米特）多项式 $H_n(x)$ 的值。题目明确要求使用**递归**的方式来实现。

多项式的定义如下：
$$
H_n(x) = 
\begin{cases} 
1 & \text{如果 } n = 0 \\
2x & \text{如果 } n = 1 \\
2xH_{n-1}(x) - 2(n-1)H_{n-2}(x) & \text{如果 } n > 1
\end{cases}
$$

输入为整数 `n` 和 `x`，输出为计算结果，保留两位小数。

### 解题思路

这是一个将数学递归公式直接翻译成代码的典型问题。我们可以创建一个函数，例如 `hermite(n, x)`，该函数将完全模仿题目中给出的定义。

#### 1. 递归函数设计

函数 `hermite(n, x)` 需要处理三种情况：

-   **基本情况 (Base Case) 1**: 如果 `n` 等于 `0`，函数直接返回 `1`。这是递归的第一个出口。
-   **基本情况 (Base Case) 2**: 如果 `n` 等于 `1`，函数返回 `2 * x`。这是递归的第二个出口。
-   **递归步骤 (Recursive Step)**: 如果 `n` 大于 `1`，函数需要调用自身来计算 `H_{n-1}(x)` 和 `H_{n-2}(x)` 的值。然后根据公式 `2*x*H_{n-1}(x) - 2*(n-1)*H_{n-2}(x)` 计算并返回结果。

#### 2. 数据类型

由于 `x` 可以是任意正整数，并且计算过程中可能出现小数，我们应该使用浮点数类型（例如 `double`）来处理 `x` 和函数的返回值，以确保精度。

#### 3. 主函数逻辑

-   在 `main` 函数中，读取整数 `n` 和 `x` 的值。
-   调用我们定义的 `hermite(n, x)` 函数。
-   获取返回值，并使用 `std::fixed` 和 `std::setprecision(2)` 进行格式化，以保留两位小数后输出。

### C++代码实现

```cpp
#include <iostream>
#include <iomanip>

// 递归函数计算 Hermite 多项式
double hermite(int n, double x) {
    // 基本情况 n = 0
    if (n == 0) {
        return 1.0;
    }
    // 基本情况 n = 1
    if (n == 1) {
        return 2.0 * x;
    }
    // 递归步骤 n > 1
    return 2.0 * x * hermite(n - 1, x) - 2.0 * (n - 1) * hermite(n - 2, x);
}

int main() {
    int n;
    double x;
    std::cin >> n >> x;

    double result = hermite(n, x);

    // 按要求格式化输出
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;

    return 0;
}
```

**注意**: 虽然纯粹的递归可以解决这个问题，但在 `n` 很大的情况下，这种方法效率较低，因为它会重复计算许多相同的子问题（例如，计算 `hermite(5,x)` 和 `hermite(4,x)` 都会需要计算 `hermite(3,x)`）。对于本题的数据范围（通常较小），直接递归是可行的。如果 `n` 非常大，则需要使用记忆化搜索或动态规划进行优化。
