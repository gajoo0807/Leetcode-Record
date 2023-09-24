class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));
        dp[0][0] = double(poured);
        double overflow;
        for(int i=0; i <  query_row; i++){
            for(int j = 0; j <= i; j++){
                overflow = (dp[i][j] - 1.0) / 2.0;
                if(overflow > 0){
                    dp[i + 1][j] += overflow;
                    dp[i + 1][j + 1] += overflow; 
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
