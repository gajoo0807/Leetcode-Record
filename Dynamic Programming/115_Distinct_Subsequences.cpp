class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // Initial conditions: dp[i][0] = 1 (where 0 <= i < m)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        // Dynamic programming process
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
};