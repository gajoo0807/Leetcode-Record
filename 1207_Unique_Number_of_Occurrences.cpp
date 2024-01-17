class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> mp;
        for(const int &item: arr){
            if(mp.find(item) == mp.end()) mp[item] = 0;
            mp[item] ++;
        }
        std::unordered_set<int> s;
        for(auto x: mp){
            s.insert(x.second);
        }
        return mp.size() == s.size();
    }
};