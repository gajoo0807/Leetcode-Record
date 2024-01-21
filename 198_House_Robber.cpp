class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> unselect(2, 0);
        vector<int> select(2, 0);

        select[0] = nums[0];

        for(int i = 1; i < n; i ++){
            unselect[i % 2] = max(unselect[(i - 1) % 2], select[(i - 1) % 2]);
            select[i %2] = unselect[(i - 1) %2] + nums[i];
        }
        return max(unselect[(n - 1) % 2], select[(n - 1) % 2]);
    }
};