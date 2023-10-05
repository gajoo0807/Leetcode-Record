class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> count;
        for(auto num: nums){
            if(count.find(num) != count.end())
                count[num]++;
            else
                count[num]=1;
        }
        for(const auto& pair : count){
            if(pair.second > n/3)
                ans.push_back(pair.first);
        }
        return ans;
    }
};
