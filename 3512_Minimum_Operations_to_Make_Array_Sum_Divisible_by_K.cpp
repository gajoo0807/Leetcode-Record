class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        int i = sum / k;
        i *= k;        
        return (sum - i);
    }
};