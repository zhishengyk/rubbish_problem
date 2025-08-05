## 两数之和问题解法

本题要求我们在一组不同的正整数中，找出有多少对数的和等于给定的目标值 `x`。这是一个经典的“两数之和 (Two Sum)”问题。

### 核心思路

对于数组中的每一个数 `a_i`，我们需要快速判断它的“另一半” `x - a_i` 是否也存在于数组中。

#### 方法一：排序 + 双指针

1.  **排序**: 首先将整个数组 `a` 升序排序。时间复杂度 $O(N \log N)$。
2.  **双指针**:
    *   设置两个指针，`left` 指向数组开头，`right` 指向数组末尾。
    *   当 `left < right` 时循环：
        *   计算 `sum = a[left] + a[right]`。
        *   如果 `sum == x`，说明我们找到了一对。因为数组中没有重复的数，所以直接将计数器加一，然后同时移动两个指针 (`left++`, `right--`) 去寻找新的可能组合。
        *   如果 `sum < x`，说明和太小了，需要增大。我们将 `left` 指针右移，尝试一个更大的数。
        *   如果 `sum > x`，说明和太大了，需要减小。我们将 `right` 指针左移，尝试一个更小的数。
3.  这个双指针扫描的过程是 $O(N)$ 的。总时间复杂度为 $O(N \log N)$。

#### 方法二：哈希表

1.  **使用哈希集合**: 我们可以用 `std::unordered_set` 来存储已经遍历过的数字。
2.  遍历数组中的每个数 `num`：
    *   计算我们需要的“另一半”：`complement = x - num`。
    *   在哈希集合中查找 `complement` 是否存在。
    *   如果存在，就说明我们找到了一个数对，计数器加一。
    *   将当前的 `num` 加入哈希集合。
3.  为了避免重复计数（例如 `(a, b)` 和 `(b, a)` 被算作两次），并且满足 `i < j` 的条件，我们可以在遍历时先查找再插入。这样当我们处理 `a[j]` 时，如果找到了 `a[i]` (`i < j`)，就算作一对。
4.  时间复杂度是 $O(N)$，空间复杂度是 $O(N)$。

#### 方法三：布尔/计数数组（优化哈希）

考虑到题目中数字的范围 `1 <= a_i <= 1000000` 并不算特别大，我们可以使用一个大小固定的数组来代替哈希表，以获得更快的速度和更简单的实现。

1.  **建立“存在”标记**:
    *   创建一个布尔数组 `bool seen[1000001] = {false};`。
    *   遍历一遍输入的 `n` 个数，对于每个数 `num`，设置 `seen[num] = true`。这一步的时间复杂度是 $O(N)$。

2.  **查找数对**:
    *   再次遍历输入的 `n` 个数。对于每个数 `a[i]`：
    *   计算它的“另一半” `complement = x - a[i]`。
    *   检查 `complement` 是否在 `seen` 数组中被标记为 `true`。
    *   **避免重复计数**: 如果我们直接计数，那么 `(a_i, a_j)` 这个数对会在我们遍历到 `a_i` 和 `a_j` 时被各计算一次。为了只计算一次，我们可以加一个限制，比如只在 `a[i] < complement` 的时候才计数。这个条件同时也巧妙地处理了 `a[i] == complement` 的情况（因为 `a_i < a_i` 为假），这在本题中不会发生，因为所有数都是不同的。

### 算法流程 (方法三)

1.  创建一个大小为 1000001 的布尔数组 `seen`。
2.  读取 `n` 和 `n` 个整数，填充 `seen` 数组。
3.  读取目标值 `x`。
4.  初始化计数器 `count = 0`。
5.  遍历原始读入的 `n` 个整数 `a[i]`：
    *   `complement = x - a[i]`
    *   如果 `a[i] < complement`，并且 `complement` 在合法范围内且 `seen[complement]` 为 `true`，则 `count++`。
6.  输出 `count`。

### 代码实现 (方法三)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_VAL = 1000001;
bool seen[MAX_VAL] = {false};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] < MAX_VAL) {
            seen[a[i]] = true; // 标记出现过的数字
        }
    }

    int x;
    std::cin >> x;

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int complement = x - a[i];
        
        // a[i] < complement 这个条件确保每个数对只被计算一次
        // 同时也排除了 a[i] * 2 = x 的情况
        if (a[i] < complement) {
            if (complement > 0 && complement < MAX_VAL && seen[complement]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```
