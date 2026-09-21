class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftToRight(n, 0);
        vector<int> rightToLeft(n, 0);

        leftToRight[0] = 1;
        rightToLeft[n-1] = 1;
        for(int i = 1; i < n; i ++){
            if(ratings[i] > ratings[i-1])
                leftToRight[i] = leftToRight[i-1] + 1;
            else if(ratings[i] <= ratings[i-1])
                leftToRight[i] = 1;
            if(ratings[n-1-i] > ratings[n-i]) 
                rightToLeft[n-1-i] = rightToLeft[n-i] + 1;
            else if(ratings[n-1-i] <= ratings[n-i])
                rightToLeft[n-1-i] = 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i ++)
            ans += max(leftToRight[i], rightToLeft[i]);
        return ans;
    }
};