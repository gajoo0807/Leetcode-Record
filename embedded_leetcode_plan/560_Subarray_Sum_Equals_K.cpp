class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int find = 0, sum = 0;
        mp[0] = 1;
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i ++){
            sum += nums[i];
            find = sum - k;
            if(mp.find(find) != mp.end()) ans += mp[find];
            mp[sum] ++;
        }
        return ans;
    }
};