class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int ans = 0;
        for(auto& it: nums){
            numSet.insert(it);
        }
        
        for(auto& it: numSet){
            if(numSet.find(it - 1) != numSet.end()) continue;
            int j = 1;
            while(numSet.find(it + j) != numSet.end()) j ++;
            ans = max(ans, j);
        }
        return ans;
    }
};