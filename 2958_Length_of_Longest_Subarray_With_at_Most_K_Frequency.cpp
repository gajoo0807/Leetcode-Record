class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int n = nums.size(), ans = 0, r = 0, l = 0;
        unordered_map<int, int> count;
        int cur;

        while(r < n){
            cur = nums[r++];
            count[cur] ++;
            if(count[cur] > k){
                while(count[cur] != count[nums[l]] && l < r) {
                    count[nums[l]]--;
                    l ++;
                }
                l ++;
                count[cur] --;
            }
            ans = max(ans, r - l) ;
        }
        return ans;
    }
};