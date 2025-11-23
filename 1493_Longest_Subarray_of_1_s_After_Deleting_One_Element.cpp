class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n = nums.size();
            int l = 0;
            int zero_count = 0;
            int max_len = 0;
    
            // 1. 擴展視窗 (R 指針從左向右移動)
            for (int r = 0; r < n; ++r) {
                
                if (nums[r] == 0) {
                    zero_count++;
                }
    
                // 2. 收縮視窗 (L 指針移動，維持條件：zero_count <= 1)
                // 如果視窗內有超過一個 0，則收縮視窗左側
                while (zero_count > 1) {
                    if (nums[l] == 0) {
                        zero_count--;
                    }
                    l++;
                }
    
                // 3. 計算當前視窗的長度
                // 當前視窗 [l, r] 的長度是 (r - l + 1)。
                // 因為我們必須刪除一個元素（那個 0，或者在全 1 陣列中刪除一個 1），
                // 所以結果長度是：(視窗長度) - 1
                // (r - l + 1) - 1 = r - l
                
                max_len = max(max_len, r - l);
            }
    
            return max_len;
        }
    };