class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // 1. 計算總和的餘數 (Total Remainder)
        // 使用 long long 防止加法溢位，雖然最後只需要 % p
        long long total_sum = 0;
        for (int num : nums) {
            total_sum = (total_sum + num) % p; 
        }
        
        int target_rem = total_sum % p;
        
        // 如果總和已經能被 p 整除，不需要移除任何元素
        if (target_rem == 0) return 0;

        // 2. Hash Map 記錄 (PrefixSum % p -> Index)
        // 初始化 {0: -1} 是為了處理「子陣列從索引 0 開始」的情況
        unordered_map<int, int> last_seen;
        last_seen[0] = -1;

        int n = nums.size();
        int min_len = n; 
        long long current_sum = 0;

        // 3. 遍歷陣列
        for (int i = 0; i < n; ++i) {
            // 邊加邊模，避免溢位，並保持 current_sum 在 [0, p-1] 範圍
            current_sum = (current_sum + nums[i]) % p;

            // 公式推導：
            // (CurrentSum - TargetPrefix) % p == target_rem
            // => TargetPrefix = (CurrentSum - target_rem) % p
            // +p 是為了處理負數結果 (C++ 的 % 對負數行為)
            int needed_prefix = (current_sum - target_rem + p) % p;

            // 如果 Map 中存在這個需要的餘數，說明找到了一段合法的區間
            if (last_seen.count(needed_prefix)) {
                // 計算長度並更新最小值
                min_len = min(min_len, i - last_seen[needed_prefix]);
            }

            // 更新當前餘數的最新位置 (我們想要最短子陣列，所以越靠右越好，這裡直接覆蓋)
            last_seen[current_sum] = i;
        }

        // 4. 檢查是否移除了整個陣列 (題目不允許)
        return (min_len == n) ? -1 : min_len;
    }
};