## 舞会配对问题解法

本题要求模拟一个舞会配对的过程。男士和女士分别排成两队，每次从队首各取一人配对，配对后的人会回到各自队伍的末尾，等待下一轮。这个过程会重复指定的“舞曲数目”次。

### 核心思路

这个问题非常适合使用队列（Queue）来解决，因为队列具有“先进先出”（FIFO）的特性，完美地模拟了排队的过程。

1.  **初始化**:
    *   创建两个队列，一个用于男士 (`men`)，另一个用于女士 (`women`)。
    *   根据输入的男士和女士数量，将他们的编号（从1开始）依次加入各自的队列中。

2.  **模拟配对过程**:
    *   我们需要一个循环，循环次数等于输入的“舞曲数目”。
    *   在每次循环（即每首舞曲）中：
        *   从男士队列的队首取出一人 (`men.front()`)，并将其从队列中移除 (`men.pop()`)。
        *   从女士队列的队首取出一人 (`women.front()`)，并将其从队列中移除 (`women.pop()`)。
        *   输出这对舞伴的编号。
        *   将刚才配对的男士和女士重新加入到他们各自队列的末尾 (`men.push()` 和 `women.push()`)，这样他们就可以参加下一轮的配对。

3.  **循环**: 重复此过程，直到所有舞曲结束。

### 代码实现

```cpp
#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int men_count, women_count;
    std::cin >> men_count >> women_count;
    int songs_count;
    std::cin >> songs_count;

    std::queue<int> men, women;
    for (int i = 1; i <= men_count; ++i) {
        men.push(i);
    }
    for (int i = 1; i <= women_count; ++i) {
        women.push(i);
    }

    for (int i = 0; i < songs_count; ++i) {
        int man = men.front();
        men.pop();
        int woman = women.front();
        women.pop();

        std::cout << man << " " << woman << std::endl;

        men.push(man);
        women.push(woman);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
```

### 算法分析

*   **时间复杂度**: 假设舞曲数目为 $k$。每次配对操作（包括取出、输出和重新加入队列）都是常数时间 $O(1)$ 的。这个操作会重复 $k$ 次，因此总的时间复杂度是 $O(k)$。初始化队列的时间复杂度为 $O(\text{men\_count} + \text{women\_count})$。所以，总的时间复杂度是 $O(\text{men\_count} + \text{women\_count} + k)$。
*   **空间复杂度**: 我们需要两个队列来存储所有男士和女士的编号，所以空间复杂度是 $O(\text{men\_count} + \text{women\_count})$。
