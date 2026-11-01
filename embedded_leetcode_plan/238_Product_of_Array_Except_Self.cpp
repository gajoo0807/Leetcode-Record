class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefixProduct = 1, suffixProduct = 1;
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i ++){
            prefixProduct *= nums[i-1];
            suffixProduct *= nums[n-i];
            ans[i] *=  prefixProduct;
            ans[n-i-1] *= suffixProduct;
        }
        return ans;
    }
};