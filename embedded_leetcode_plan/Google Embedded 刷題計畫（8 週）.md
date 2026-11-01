# Google Embedded 刷題計畫（8 週）

Oct 30, 2026 · @Gajoo

## 總覽

8 週內刷約 130 題 LeetCode（以 medium 為主），加上 6 個 embedded 實作題和 4 次 mock，目標是能在 45 分鐘內不靠 IDE 寫出並講清楚最佳解。

時間假設：平日每天約 1 小時（1–2 題），週末各 2–3 小時（複習 + 實作題或 mock），每週約 10 小時。

| 階段 | 重點 | 題數 |
| --- | --- | --- |
| Week 1–2 | 基礎題型 + C 暖身 | 約 35 |
| Week 3–4 | Tree / Graph / Heap + bit manipulation | 約 40 |
| Week 5–6 | DP / Interval / Trie + embedded 實作 | 約 35 + 6 實作 |
| Week 7–8 | Google tag 混合題 + mock + domain 輪 | 約 20 + 4 mock |

每週節奏：週一至週五刷新題；週六做實作題或 mock；週日重寫本週做錯或超時的題。

## Week 1–2：基礎題型 + C 暖身

重點是把高頻基礎題寫到反射級，同時把「不靠 STL 的 C」手感找回來。

### Week 1：Array / Hash / Two Pointers / Sliding Window / Stack

- [x] 49 Group Anagrams
- [x] 128 Longest Consecutive Sequence
- [x] 238 Product of Array Except Self
- [ ] 15 3Sum
- [ ] 11 Container With Most Water
- [ ] 3 Longest Substring Without Repeating Characters
- [ ] 424 Longest Repeating Character Replacement
- [ ] 76 Minimum Window Substring
- [ ] 560 Subarray Sum Equals K
- [ ] 239 Sliding Window Maximum
- [ ] 42 Trapping Rain Water
- [ ] 739 Daily Temperatures
- [ ] 84 Largest Rectangle in Histogram
- [ ] 155 Min Stack
- [ ] 150 Evaluate Reverse Polish Notation
- [ ] 394 Decode String

### Week 2：Binary Search / Linked List

- [ ] 33 Search in Rotated Sorted Array
- [ ] 153 Find Minimum in Rotated Sorted Array
- [ ] 875 Koko Eating Bananas
- [ ] 1011 Capacity To Ship Packages Within D Days
- [ ] 981 Time Based Key-Value Store
- [ ] 162 Find Peak Element
- [ ] 206 Reverse Linked List（迭代 + 遞迴各一次）
- [ ] 92 Reverse Linked List II
- [ ] 25 Reverse Nodes in k-Group
- [ ] 142 Linked List Cycle II
- [ ] 143 Reorder List
- [ ] 138 Copy List with Random Pointer
- [ ] 2 Add Two Numbers
- [ ] 19 Remove Nth Node From End of List

### C 暖身（週末，純 C 寫）

- [ ] 自己實作 `memcpy`、`memmove`（處理 overlap）、`strlen`、`strcmp`
- [ ] 8 String to Integer (atoi)：溢位處理要講清楚
- [ ] 用 C 寫單向 linked list：insert / delete / reverse，含正確 free

## Week 3–4：Tree / Graph / Heap + Bit Manipulation

Graph 是 Google 最愛考的一塊，這兩週投入最多時間；bit manipulation 是 embedded 職缺的加分題。

### Week 3：Tree / Heap / Bit

- [ ] 102 Binary Tree Level Order Traversal
- [ ] 236 Lowest Common Ancestor of a Binary Tree
- [ ] 98 Validate Binary Search Tree
- [ ] 230 Kth Smallest Element in a BST
- [ ] 105 Construct Binary Tree from Preorder and Inorder
- [ ] 124 Binary Tree Maximum Path Sum
- [ ] 297 Serialize and Deserialize Binary Tree
- [ ] 215 Kth Largest Element in an Array（heap + quickselect 兩種）
- [ ] 23 Merge k Sorted Lists
- [ ] 295 Find Median from Data Stream
- [ ] 621 Task Scheduler
- [ ] 191 Number of 1 Bits
- [ ] 190 Reverse Bits
- [ ] 338 Counting Bits
- [ ] 136 / 137 Single Number I / II
- [ ] 371 Sum of Two Integers（不用 +）
- [ ] 201 Bitwise AND of Numbers Range

### Week 4：Graph / Union-Find

- [ ] 200 Number of Islands
- [ ] 133 Clone Graph
- [ ] 994 Rotting Oranges（multi-source BFS）
- [ ] 417 Pacific Atlantic Water Flow
- [ ] 207 / 210 Course Schedule I / II（topological sort）
- [ ] 269 Alien Dictionary
- [ ] 127 Word Ladder
- [ ] 743 Network Delay Time（Dijkstra）
- [ ] 787 Cheapest Flights Within K Stops
- [ ] 1631 Path With Minimum Effort
- [ ] 684 Redundant Connection（Union-Find）
- [ ] 721 Accounts Merge
- [ ] 323 Number of Connected Components
- [ ] 399 Evaluate Division
- [ ] 329 Longest Increasing Path in a Matrix（DFS + memo）

### Bit 實戰（週末，純 C）

- [ ] 實作 bitmap allocator：`alloc_id()` / `free_id(id)`，用 `uint32_t` 陣列 + find-first-zero
- [ ] 寫 `set_bits(reg, pos, len, val)` / `get_bits(reg, pos, len)` 及 endianness 轉換

## Week 5–6：DP / Interval / Trie + Embedded 實作

DP 只練到 Google 常見的 1D/2D 程度，你已經會的 Digit DP、sparse table 不再加碼；省下的時間給 embedded 實作題。

### Week 5：DP / Interval / Trie

- [ ] 322 Coin Change
- [ ] 300 Longest Increasing Subsequence（含 O(n log n)）
- [ ] 139 Word Break
- [ ] 1143 Longest Common Subsequence
- [ ] 72 Edit Distance
- [ ] 416 Partition Equal Subset Sum
- [ ] 198 / 213 House Robber I / II
- [ ] 91 Decode Ways
- [ ] 56 Merge Intervals
- [ ] 57 Insert Interval
- [ ] 435 Non-overlapping Intervals
- [ ] 253 Meeting Rooms II
- [ ] 208 Implement Trie
- [ ] 211 Design Add and Search Words
- [ ] 212 Word Search II

### Week 6：Design 類 + Embedded 實作（純 C 為主）

LeetCode design 題：

- [ ] 146 LRU Cache（先 C++，再用 C 手寫 hash + 雙向 list）
- [ ] 622 Design Circular Queue
- [ ] 359 Logger Rate Limiter
- [ ] 362 Design Hit Counter
- [ ] 380 Insert Delete GetRandom O(1)

Embedded 實作（每題限時 45 分鐘，寫完自己設計 test case）：

- [ ] Ring buffer：固定大小、power-of-2 mask、滿/空判斷；延伸到 SPSC lock-free（講清楚 memory barrier 放哪）
- [ ] Fixed-size memory pool：free list 實作 `pool_alloc` / `pool_free`
- [ ] Aligned malloc / free：用 `malloc` 包出 `aligned_malloc(size, align)`
- [ ] 簡易 heap allocator：first-fit + 合併相鄰 free block
- [ ] TLV / 封包 parser：處理長度越界、截斷、未知 type
- [ ] Timer wheel 或 software timer：`add_timer` / `cancel_timer` / `tick()`

## Week 7–8：Mock、Domain 輪、Behavioral

最後兩週不再開新主題，改成模擬真實面試的「隨機題 + 口述 + 限時」。

### 混合刷題

- [ ] LeetCode Google tag（近 6 個月、依頻率排序）medium 刷 15–20 題，每題限時 35 分鐘
- [ ] 重寫 Week 1–6 所有標記「做錯/超時」的題

### Mock interview（4 次）

- [ ] Mock 1：2 題 medium（45 分鐘），在 Google Doc 寫
- [ ] Mock 2：1 題 graph + 1 題 design（LRU / rate limiter 類）
- [ ] Mock 3：1 題 embedded 實作（ring buffer / allocator）純 C
- [ ] Mock 4：完整模擬一天（2 coding + 1 domain + 1 behavioral）

找同事、朋友或線上平台互相 mock；都找不到就錄影自己講解並回放。

### Domain 輪準備（C / OS / Concurrency）

- [ ] C：`volatile`、`const` 指標組合、struct padding / `packed`、endianness、undefined behavior 常見例子
- [ ] Concurrency：mutex vs spinlock vs semaphore、deadlock 四條件、priority inversion、memory barrier / atomic
- [ ] Interrupt：ISR 能做什麼、不能做什麼、top half / bottom half、中斷延遲
- [ ] Memory：virtual memory、cache coherency、DMA 與 cache 一致性（flush / invalidate）
- [ ] 準備 2–3 個自己的 debug 故事：用 Wi-Fi TX/RX、SDIO/PCIe、DMA ring 的實際案例，講清楚症狀 → 假設 → 驗證 → 修正

### Behavioral（Googleyness & Leadership）

- [ ] 用 STAR 整理 5–6 個故事：解決困難 bug、推動跨團隊合作、意見衝突、失敗與學習、自動化工具帶來的影響
- [ ] 每個故事配一個可量化的結果（省下的時間、解掉的 issue 數）

## 練習方法與每題檢核清單

每題都照面試流程走一遍，不只是 AC；20 分鐘沒思路就看解答，隔 3 天重寫。

1. 釐清題意：問輸入範圍、是否有重複、空輸入、記憶體限制
2. 先講 brute force 與複雜度，再講優化思路
3. 在純文字編輯器寫（關掉自動補全、不編譯）
4. 手動 dry run 一個一般 case + 兩個 edge case
5. 說出時間 / 空間複雜度，並主動提一個 follow-up（資料太大、多執行緒、記憶體受限怎麼辦）

錄一個簡單錯題本：題號、卡關點、這題的關鍵 pattern，每週日從這裡挑題重寫。

由於目標涵蓋 display、embedded 和 modem protocol stack 職缺，實際投遞後可依招募人員說明的面試組成，把 Week 7–8 的比重往 coding 或 domain 調。
