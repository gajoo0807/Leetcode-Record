class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;

        for(int i = 0; i < n; i ++){
            string key = strs[i];
            sort(key.begin(), key.end());
            groups[key].push_back(strs[i]);
        }
        ans.reserve(groups.size());
        for (auto& [key, group] : groups)
            ans.push_back(move(group));      
        return ans;
    }
};