class Solution {
public:
    // 使用 result 作為差分數組，最終作為結果陣列
    std::vector<int> getModifiedArray(int length, const std::vector<std::vector<int>>& updates) {
        // 1. 初始化差分數組 (Difference Array)
        std::vector<int> result(length, 0); 
        
        // 2. O(U) 區間更新操作
        for (const auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int increment = update[2];
            
            // 區間起點：累加增量
            result[start] += increment;
            
            // 區間終點+1：抵消增量（如果仍在界限內）
            if (end + 1 < length) {
                result[end + 1] -= increment;
            }
        }
        
        // 3. O(N) 前綴和還原 (Prefix Sum)
        // 遍歷差分數組，將其轉化為最終結果陣列
        for (int i = 1; i < length; ++i) {
            result[i] += result[i-1];
        }
        
        return result;
    }
};