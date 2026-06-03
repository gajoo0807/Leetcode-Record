class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        // 找各自最早結束時間（= 最早開始 + duration，但要注意是 startTime+duration 最小）
        int minEndLand  = INT_MAX;
        int minEndWater = INT_MAX;

        for(int i = 0; i < (int)landStartTime.size(); i++)
            minEndLand = min(minEndLand, landStartTime[i] + landDuration[i]);

        for(int i = 0; i < (int)waterStartTime.size(); i++)
            minEndWater = min(minEndWater, waterStartTime[i] + waterDuration[i]);

        int ans = INT_MAX;

        // 先水後陸：水最早結束後，選最划算的陸地設施
        for(int i = 0; i < (int)landStartTime.size(); i++)
            ans = min(ans, max(landStartTime[i], minEndWater) + landDuration[i]);

        // 先陸後水：陸最早結束後，選最划算的水上設施
        for(int i = 0; i < (int)waterStartTime.size(); i++)
            ans = min(ans, max(waterStartTime[i], minEndLand) + waterDuration[i]);

        return ans;
    }
};