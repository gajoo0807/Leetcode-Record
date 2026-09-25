class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int min_even = INT_MAX, min_odd = INT_MAX;
        for(auto &it: nums1){
            if(it % 2) {
                min_odd = min(min_odd, it);
            }
            else {
                min_even = min(min_even, it);
            }
        }
        if(min_even == INT_MAX || min_odd == INT_MAX) return true;
        if(min_even > min_odd) return true;
        return false;
    }
};