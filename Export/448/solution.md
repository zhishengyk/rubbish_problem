## 问题448 题解

### 题目分析

本题要求我们对一个给定的正整数 `n` 进行质因数分解，并以从小到大的顺序输出所有的质因子。题目特别指定需要使用**递归**方法。

例如，对于 `18`，其质因子是 `2, 3, 3`，因为 `18 = 2 * 3 * 3`。

### 解题思路

质因数分解通常是通过试除法来完成的。我们可以从最小的质数 `2` 开始，尝试看它是否能整除 `n`。这个过程很自然地可以用递归来表达。

#### 1. 递归函数设计

我们可以设计一个递归函数，例如 `factorize(number, divisor)`，它接受两个参数：
-   `number`: 当前需要被分解的数。
-   `divisor`: 当前用来尝试整除的因子。

这个函数的目标是找到并打印 `number` 的一个最小质因子，然后对商继续进行分解。

#### 2. 递归逻辑

1.  **起始调用**: 在 `main` 函数中，我们从最小的质数 `2` 开始尝试，所以初始调用是 `factorize(n, 2)`。

2.  **函数内部逻辑 `factorize(num, div)`**:
    -   **基本情况1**: 如果 `num` 等于 `1`，说明分解已经完成，递归结束。
    -   **剪枝/优化**: 如果 `div * div > num`，这意味着从 `div` 到 `sqrt(num)` 都没能找到 `num` 的因子。因此，`num` 本身（如果大于1）必定是一个质数，它是最后一个质因子。我们打印它，然后结束递归。
    -   **找到一个因子**: 如果 `div` 能够整除 `num` (`num % div == 0`)：
        -   我们找到了一个质因子 `div`。打印它。
        -   接下来我们需要分解 `num / div`。由于可能存在重复的质因子（例如18中的两个3），我们应该继续用同一个 `div` 去尝试分解新的商。所以，递归调用 `factorize(num / div, div)`。
    -   **未找到因子**: 如果 `div` 不能整除 `num`：
        -   我们需要尝试下一个可能的因子。所以，递归调用 `factorize(num, div + 1)`。

通过这种方式，我们总是从最小的可能因子开始尝试，因此输出的质因子自然就是从小到大排序的。

### C++代码实现

```cpp
#include <iostream>

/**
 * @brief 递归地寻找并打印质因子
 * @param n 当前要分解的数
 * @param divisor 当前尝试的除数
 */
void find_prime_factors(int n, int divisor) {
    // 基本情况：分解完成
    if (n == 1) {
        return;
    }
    
    // 优化：如果除数的平方大于n，则n本身必为质数
    if (divisor * divisor > n) {
        std::cout << n << " ";
        return;
    }

    if (n % divisor == 0) {
        // 找到了一个质因子
        std::cout << divisor << " ";
        // 继续用同一个因子分解商
        find_prime_factors(n / divisor, divisor);
    } else {
        // 尝试下一个因子
        find_prime_factors(n, divisor + 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    
    // 从最小的质数2开始分解
    find_prime_factors(n, 2);
    std::cout << std::endl;
    
    return 0;
}
```
这个实现遵循了题目要求，使用递归完成了质因数分解，并保证了输出的有序性。
