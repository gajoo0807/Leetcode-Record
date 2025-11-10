class Solution {
    public:
        int minOperations(vector<int>& nums) {
            long long ans = 0;
            vector<int> st;
    
            for(auto x: nums){
                if(x == 0){
                    st.clear();
                    continue;
                }
    
                while(!st.empty() && st.back() > x) st.pop_back();
                if(st.empty() || st.back() < x){
                    st.push_back(x);
                    ans++;
                }
            }
            return (int)ans;
        }
    };