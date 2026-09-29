class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> gap(n-1, 0);
        for(int i = 0; i < n - 1; i ++){
            gap[i] = (nums[i+1] - nums[i] <= maxDiff)?0:1;
        }
        vector<int> prefixSum(n-1, 0);
        int sum = 0;
        for(int i = 0; i < n - 1; i ++){
            sum += gap[i];
            prefixSum[i] = sum;
        }
        int ansLen = queries.size();
        vector<bool> ans(ansLen, 0);
        for(int i = 0; i < ansLen; i ++){
            int u = queries[i][0], v = queries[i][1];
            if (u > v) swap(u, v);
            if (u == v) { ans[i] = true; continue; }
            int leftSum = (u > 0) ? prefixSum[u-1] : 0;
            ans[i] = (prefixSum[v-1] - leftSum) == 0;
        }
        return ans;
    }
};