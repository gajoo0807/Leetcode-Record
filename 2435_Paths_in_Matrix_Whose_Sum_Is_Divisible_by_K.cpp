class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0]%k] = 1;
        int accu = grid[0][0] % k;
        for(int i = 1; i < m; i++){
            accu += grid[i][0];
            accu %= k;
            dp[i][0][accu] = 1;
        }
        accu = grid[0][0] % k;
        for(int j = 1;j < n; j ++){
            accu += grid[0][j];
            accu %= k;
            dp[0][j][accu] = 1;
        }
        accu = grid[0][0] % k;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j ++){
                for(int idx = 0; idx < k; idx ++){
                    long long num_1 = dp[i][j-1][idx];
                    long long num_2 = dp[i-1][j][idx];
                    long long accu = (idx + grid[i][j])%k;
                    dp[i][j][accu] = (num_1 + num_2) % MOD;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};