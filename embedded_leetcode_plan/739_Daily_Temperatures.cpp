class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i ++){
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int cur = st.top(); st.pop();
                ans[cur] = i - cur;
            }
            st.push(i);
        }
        return ans;
    }
};