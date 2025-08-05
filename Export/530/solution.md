## 问题530 题解

### 题目分析

本题要求我们在一个 $N \times M$ 的矩阵中，找到一个**面积最小**的子矩阵，使得该子矩阵内所有元素的**和不小于**给定的值 $K$。

这是一个二维的最优化问题。一个朴素的解法是枚举所有可能的子矩阵，这需要四层循环来确定子矩阵的左上角和右下角，时间复杂度至少为 $O(N^2 M^2)$，对于本题的数据规模来说过高。我们需要一种更高效的方法。

### 解题思路：降维与滑动窗口

解决这类二维问题的经典思路是**降维**，将二维问题转化为多个一维问题来解决。我们可以通过固定子矩阵的**上下边界**，然后在这个确定的“条带”中寻找一个宽度最小的、满足条件的子矩阵。

1.  **枚举上下边界**:
    -   我们使用两层循环来枚举所有可能的子矩阵上下边界组合，即 `top_row` 和 `bottom_row`。`top_row` 从 `0` 到 `N-1`，`bottom_row` 从 `top_row` 到 `N-1`。

2.  **构建一维数组**:
    -   对于每一对固定的 `(top_row, bottom_row)`，我们可以将这两行以及它们之间的所有行“压缩”成一个一维数组。
    -   这个一维数组 `col_sums` 的长度为 $M$，其中 `col_sums[j]` 表示原矩阵中第 $j$ 列，从 `top_row` 到 `bottom_row` 的元素之和。

3.  **转化为一维问题**:
    -   现在，对于这个一维数组 `col_sums`，问题就变成了：**找到一个和不小于 $K$ 的、长度最小的连续子数组**。
    -   这正是一个经典的**滑动窗口（双指针）**问题，我们可以在线性时间 $O(M)$ 内解决它。

4.  **滑动窗口求解**:
    -   使用两个指针 `left_col` 和 `right_col` 在 `col_sums` 数组上滑动。
    -   不断扩大窗口（移动 `right_col`），直到窗口内的和 `current_sum >= K`。
    -   一旦满足条件，我们就找到了一个可行解。其宽度为 `right_col - left_col + 1`。对应的子矩阵面积为 `(bottom_row - top_row + 1) * (right_col - left_col + 1)`。我们用这个面积来更新全局的最小面积 `min_area`。
    -   然后，我们收缩窗口（移动 `left_col`），寻找可能更短的、但仍然满足条件的子数组。

#### 算法步骤

1.  初始化 `min_area = infinity`。
2.  外层循环：`for top_row from 0 to N-1`:
    a. 创建一个大小为 $M$ 的一维数组 `col_sums`，并全部初始化为0。
    b. 内层循环：`for bottom_row from top_row to N-1`:
        i.   **更新 `col_sums`**: 将第 `bottom_row` 行的元素累加到 `col_sums` 中。现在 `col_sums` 存储的是从 `top_row` 到 `bottom_row` 的列和。
        ii.  **应用滑动窗口**:
            -   初始化 `current_sum = 0`, `left_col = 0`。
            -   `for right_col from 0 to M-1`:
                -   `current_sum += col_sums[right_col]`。
                -   `while (current_sum >= K)`:
                    -   计算当前面积：`area = (bottom_row - top_row + 1) * (right_col - left_col + 1)`。
                    -   更新 `min_area = min(min_area, area)`。
                    -   收缩窗口：`current_sum -= col_sums[left_col]`, `left_col++`。

3.  **输出结果**:
    -   所有循环结束后，如果 `min_area` 仍然是初始的极大值，说明没有找到任何满足条件的子矩阵，输出 `-1`。
    -   否则，输出 `min_area`。

该算法的整体时间复杂度为 $O(N^2 \cdot M)$，对于 $N, M \le 100$ 的数据是完全可以接受的。
