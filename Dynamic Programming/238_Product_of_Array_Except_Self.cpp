class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefixProduct = 1;
        int suffixProduct = 1;
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i ++){
            if(i != 0) {
                prefixProduct *= nums[i-1];
                suffixProduct *= nums[n-i];
            }
            ans[i] *= prefixProduct;
            ans[n-i-1] *= suffixProduct;
        }

        return ans;
    }
};