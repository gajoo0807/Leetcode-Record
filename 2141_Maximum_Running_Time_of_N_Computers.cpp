class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total_sum = 0;
        for(auto x: batteries){
            total_sum += x;
        }
        long long right = total_sum / n;
        long long left = 1;
        long long ans = 0;
        
        while(left <= right){
            long long mid = left + (right - left)/2;

            long long vaild_energy = 0;
            for(auto x: batteries){
                if(x < mid){
                    vaild_energy += x;
                }else{
                    vaild_energy += mid;
                }
            }

            if(vaild_energy >= n * mid){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};