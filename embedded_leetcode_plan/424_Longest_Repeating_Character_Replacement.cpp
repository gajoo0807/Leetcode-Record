class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
        1 if s.size() == 1
        n if s.size() == n && all char in s is same
        sliding window: valid if (size - maxFreq <= k)
        invalid -> slide right by 1 (size unchanged), so maxLen never inflates
        maxFreq only increases; window grows only when it hits a new record
        time O(n), space O(1)
        */
        int freq[26] = {0};
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;
        int left = 0;

        for(int right = 0; right < n; right ++){
            char ch = s[right];
            freq[ch - 'A'] ++;
            maxFreq = max(maxFreq, freq[ch - 'A']);

            if((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A'] --;
                left ++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};