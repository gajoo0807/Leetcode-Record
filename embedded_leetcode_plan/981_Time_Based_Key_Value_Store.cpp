class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if(it == mp.end()) return "";
        const vector<pair<int, string>>& target = it->second;
        int l = 0, r = target.size() - 1;
        int mid;
        if(timestamp < target[l].first) return "";
        while(l < r){
            mid = l + (r - l + 1) / 2;
            if(timestamp < target[mid].first) r = mid - 1;
            else l = mid;
        }
        return target[r].second;
    }
};