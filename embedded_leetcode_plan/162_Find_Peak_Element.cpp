class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;       // peak 在左半邊（包含 mid）
            else
                l = mid + 1;   // peak 在右半邊
        }
        return l;  // l == r，即 peak 的位置
    }
};