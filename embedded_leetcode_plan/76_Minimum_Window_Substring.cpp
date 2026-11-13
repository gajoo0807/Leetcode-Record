class Solution {
public:
    string minWindow(string s, string t) {
        int freq[128] = {0}, miss = 0, m = s.size();
        int l = 0, r = 0;
        int minLength = INT_MAX;
        int start = 0;
        for(char c: t){
            freq[c] ++;
            if(freq[c] == 1) miss ++;
        }

        while(miss && r < m){
            freq[s[r]] --;
            if(freq[s[r]] == 0) miss --;
            r ++;
        }
        if(miss > 0) return "";
        r --;
        minLength = r - l + 1;
        start = l;

        while(r < m){
            while(freq[s[l]] < 0){
                freq[s[l]] ++;
                l ++;
            }
            if((r - l + 1) < minLength){
                minLength = (r - l + 1);
                start = l;
            }
            r ++;
            while(r < m && s[r] != s[l]){
                freq[s[r]] --;
                r ++;
            }
        }

        return minLength == INT_MAX? "":s.substr(start, minLength);
    }
};