class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp; // key: digit sum, value: (max1, max2)
        int ans = -1;

        for (int num : nums) {
            int sumDigits = 0, temp = num;

            // 計算數字各位數的總和
            while (temp) {
                sumDigits += temp % 10;
                temp /= 10;
            }

            auto& p = mp[sumDigits]; // 直接取 reference，減少 map 查找次數

            // 更新最大值與次大值
            if (num > p.first) {
                p.second = p.first;
                p.first = num;
            } else if (num > p.second) {
                p.second = num;
            }

            // 若有兩個以上的數字，更新最大和
            if (p.second > 0) {
                ans = max(ans, p.first + p.second);
            }
        }
        return ans;
    }
};