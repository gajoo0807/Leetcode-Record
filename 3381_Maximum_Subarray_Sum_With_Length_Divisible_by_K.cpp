class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = LLONG_MIN; 
        

        vector<long long> MinPrefix(k, LLONG_MAX);
        MinPrefix[0] = 0;
        
        long long current_sum = 0;
        
        for(int i = 0; i < n; i++) {
            current_sum += nums[i];
            int length = i + 1;
            int r = length % k;
            
            if(MinPrefix[r] != LLONG_MAX) {
                max_sum = max(max_sum, current_sum - MinPrefix[r]);
            }
            
            MinPrefix[r] = min(MinPrefix[r], current_sum);
        }
        return max_sum == LLONG_MIN ? 0 : max_sum;
    }
};