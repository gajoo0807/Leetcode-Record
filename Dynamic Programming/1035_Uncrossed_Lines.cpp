class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int equal = 0;
        for(int i = 0; i < m; i ++){
            if(equal == 1){
                dp[i][0] = 1;
                continue;
            }
            if(nums1[i] == nums2[0]){
                equal = 1;
                dp[i][0] = 1;
            }
        }
        equal = 0;
        for(int j = 0; j < n; j ++){
            if(equal == 1){
                dp[0][j] = 1;
                continue;
            }
            if(nums1[0] == nums2[j]){
                equal = 1;
                dp[0][j] = 1;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j ++){

                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};