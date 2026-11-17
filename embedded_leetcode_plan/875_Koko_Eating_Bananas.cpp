class Solution {
private:
    bool canSolve(const vector<int>& piles, int speed, int h){
        int actualHours = 0, n = piles.size();
        for(int i = 0; i < n; i ++){
            h -= ((piles[i] + speed - 1) / speed);
            if (h < 0) return false;
        }
        return h >= 0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = 0;
        int mid;
        for(int i = 0; i < n; i ++) r = max(r, piles[i]);
        while(l < r){
            mid = l + (r-l) / 2;
            if(canSolve(piles, mid, h)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};