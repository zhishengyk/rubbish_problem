## 最长单词接龙解法

本题要求在一组按长度排好序的单词中，找出最长的“接龙”序列。接龙的定义是一个单词是下一个单词的前缀。

### 核心思路：动态规划 (Dynamic Programming)

这个问题可以被看作是在一个有向无环图（DAG）中寻找最长路径的问题。
*   **节点**: 每个单词是一个节点。
*   **有向边**: 如果单词 `u` 是单词 `v` 的前缀，则有一条从 `u` 到 `v` 的有向边。
*   **目标**: 找到这个图中的最长路径（路径长度按节点数计算）。

因为输入的单词已经按长度排好序，所以如果 `u` 是 `v` 的前缀，`u` 一定在 `v` 之前出现。这保证了图是无环的（DAG），因此可以使用动态规划求解。

我们定义一个 DP 状态：
`dp[word]`: 表示以单词 `word` 结尾的最长接龙链的长度。

为了计算 `dp[word]`，我们需要找到所有是 `word` 的前缀、并且本身也在输入单词列表中的单词 `prefix`。在这些前缀中，我们找到具有最大 `dp` 值的那个，记为 `max_dp_prefix`。那么，递推关系就是：
`dp[word] = max_dp_prefix + 1`
如果 `word` 没有任何前缀在单词列表中，那么 `dp[word] = 1`。

最终的答案就是所有 `dp[word]` 中的最大值。

### 如何高效实现？

暴力地为每个单词去检查所有比它短的单词是否是其前缀，效率太低 ($O(N^2)$)。我们需要一种更高效的方式来存储和查询 DP 值。

#### 1. Trie (前缀树) 优化
一个理想的数据结构是前缀树。我们可以将所有单词插入Trie。每个节点可以额外存储一个 `dp_value`。当处理一个新单词 `w` 时，我们可以在Trie中沿着 `w` 的路径行走，并查找路径上（代表`w`的各个前缀）节点所存储的最大 `dp_value`，从而完成状态转移。这种方法的理论时间复杂度是 $O(\sum |word_i|)$，即所有单词的长度之和。

#### 2. `std::map` 实现 (更简洁)
虽然Trie性能最好，但实现起来较复杂。一个更简洁、同样可以解决问题的方法是使用 `std::map` 来存储我们的 DP 状态。

*   `std::map<std::string, int> dp;`

**算法流程 (`map` 版本)**:
1.  创建一个 `map`，`dp`，用于存储每个单词对应的最长接龙长度。
2.  初始化一个全局最大长度 `max_len = 0`。
3.  遍历按长度排序的输入单词列表中的每一个 `word`：
    *   对于当前的 `word`，我们需要找到它所有**真前缀 (proper prefix)** 中，能构成的最长接龙长度。
    *   初始化 `current_max = 0`。
    *   遍历 `word` 的所有真前缀（例如，通过 `word.substr(0, i)`），对于每个前缀 `prefix`，检查它是否存在于我们的 `dp` map中（`dp.count(prefix)`）。
    *   如果存在，说明这个前缀本身也是输入单词之一，我们可以用它的DP值来更新 `current_max`：`current_max = max(current_max, dp[prefix])`。
    *   遍历完所有前缀后，`dp[word]` 的值就确定了：`dp[word] = current_max + 1`。
    *   用 `dp[word]` 更新全局 `max_len`。
4.  所有单词处理完毕后，`max_len` 就是答案。

### 代码实现 (`map` 版本)
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }
    // 题目保证了输入是按长度排序的

    // dp[word] = 以 word 结尾的最长接龙长度
    std::map<std::string, int> dp;
    int max_len = 0;

    for (const std::string& word : words) {
        int current_max_prefix_dp = 0;
        
        // 寻找所有是输入单词的前缀，并取其最大的dp值
        for (int i = 1; i < word.length(); ++i) {
            std::string prefix = word.substr(0, i);
            if (dp.count(prefix)) {
                current_max_prefix_dp = std::max(current_max_prefix_dp, dp[prefix]);
            }
        }
        
        // 计算当前单词的dp值
        dp[word] = current_max_prefix_dp + 1;
        
        // 更新全局最大长度
        max_len = std::max(max_len, dp[word]);
    }

    // 如果没有单词，则长度为0
    if (n > 0 && max_len == 0) {
        max_len = 1;
    }

    std::cout << max_len << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```
### 算法分析 (`map` 版本)
*   **时间复杂度**: $O(\sum_{i=1}^{N} |w_i|^2 \log N)$。对于每个单词 $w_i$，我们需要遍历其所有前缀（$|w_i|$个），每个前缀操作（`substr` 和 `map`查找）大致需要 $O(|w_i| \log K)$，其中 `K` 是map中元素数量。对于本题数据量，这个复杂度是可以接受的。
*   **空间复杂度**: $O(\sum |w_i|)$，用于存储`map`。
