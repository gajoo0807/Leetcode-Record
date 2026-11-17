class Solution {
private:
    bool canSolve(const vector<int>& weights, int days, int cap) {
        int used = 1, cur = 0;
        for (int w : weights) {
            if (cur + w > cap) {          // 今天裝不下 → 開新的一天
                cur = 0;
                if (++used > days) return false;
            }
            cur += w;                     // 不論哪種情況都要裝上 w
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0, l = 0, mid;
        for(auto& i: weights) r += i;
        while(l < r){
            mid = l + (r - l) / 2;
            if(canSolve(weights, days, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};