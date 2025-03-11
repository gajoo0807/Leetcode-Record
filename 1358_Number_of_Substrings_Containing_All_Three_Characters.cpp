class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), left = 0;
        int ans = 0;
        vector<int> rec(3, 0);
        for(int right = 0; right < n; right ++){
            rec[s[right] - 'a'] ++;
            while(rec[0] && rec[1] && rec[2] ){
                ans += (n - right);
                rec[s[left] - 'a'] --;
                left++;
            }
        }
        return ans;
    }
};