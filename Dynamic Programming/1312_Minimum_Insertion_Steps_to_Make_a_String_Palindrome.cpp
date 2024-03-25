class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());

        int equal = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (equal == 1) {
                dp[i][0] = 1;
                continue;
            }
            if (s[i] == rev_s[0]) {
                equal = 1;
                dp[i][0] = 1;
            }
        }
        equal = 0;
        for (int j = 0; j < n; j++) {
            if (equal == 1) {
                dp[0][j] = 1;
                continue;
            }
            if (s[0] == rev_s[j]) {
                equal = 1;
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (s[i] == rev_s[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n - dp[n - 1][n - 1];
    }
};