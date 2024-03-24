class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int ans = 1;

        unordered_map<int, int> mp; // arr[i], longest subsequence ending in arr[i]
        for(int i = 0; i < n; i ++){
            if(mp.find(arr[i] - difference) == mp.end()){ // can't find
                mp[arr[i]] = 1;
            }else{
                mp[arr[i]] = mp[arr[i] - difference] + 1;
                ans = max(mp[arr[i]], ans);
            }
        }
        return ans;
    }
};