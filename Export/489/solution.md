## 问题489 题解

### 题目分析

这个问题要求我们计算多个可能重叠的区间的总长度。这是一个经典的区间合并问题。

### 解题思路

解决这个问题的关键在于有效地合并重叠的区间。一个标准的贪心策略是：

1.  **排序**：首先，将所有的区间按照左端点从小到大进行排序。这一步是至关重要的，它保证了我们处理区间时，总是先处理左边的区间。

2.  **合并**：遍历排序后的区间列表，并维护一个当前正在合并的区间 `merged_interval`。
    -   初始化 `merged_interval` 为列表中的第一个区间。
    -   对于后续的每一个区间 `current_interval`：
        -   **如果重叠**：`current_interval` 的左端点小于或等于 `merged_interval` 的右端点，说明它们有重叠。我们将这两个区间合并，新的 `merged_interval` 的右端点更新为 `max(merged_interval.end, current_interval.end)`。
        -   **如果不重叠**：`current_interval` 的左端点大于 `merged_interval` 的右端点，说明 `merged_interval` 已经无法再向右延伸了。此时，我们将 `merged_interval` 的长度计入总和，然后将 `merged_interval` 更新为当前的 `current_interval`，开始新的合并过程。

3.  **计算总长度**：当遍历完所有区间后，最后一个 `merged_interval` 的长度也需要被计入总长度。

这个算法的时间复杂度主要是排序的开销，即 $O(n \log n)$，其中 $n$ 是区间的数量。
