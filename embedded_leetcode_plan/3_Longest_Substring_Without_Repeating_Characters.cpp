class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[128];
        fill(freq, freq + 128, -1);
        int j = 0, n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i ++){
            j = max(j, freq[s[i]] + 1);
            freq[s[i]] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};