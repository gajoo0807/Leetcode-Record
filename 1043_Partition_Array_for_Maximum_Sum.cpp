class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for(int i = 0; i < n; i ++){
            int currMax = 0;
            for(int j = 1; j <= k && i - j + 1 >= 0; j ++){
                currMax = max(currMax, arr[i - j + 1]);
                int prev = (i - j >= 0) ? dp[i - j] : 0;
                dp[i] = max(dp[i], prev + currMax * j);
            }
        }
        return dp[n - 1];
    }
};