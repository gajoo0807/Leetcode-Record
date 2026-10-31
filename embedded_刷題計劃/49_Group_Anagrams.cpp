class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for(int i = 0; i < n; i ++){
            string key = strs[i];
            sort(key.begin(), key.end());
            map[key].push_back(strs[i]);
        }
        for(auto& it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};