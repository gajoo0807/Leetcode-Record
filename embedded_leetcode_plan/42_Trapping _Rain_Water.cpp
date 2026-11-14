class Solution {
public:
    int trap(vector<int>& height) {
        /*
        0: if all zero
        1: [1, 0, 1]
        curHeight: record height that has been counted
        maintain list [idx, height]
        got through all bar, if cur bar is i => get idxI, heightI
            if(heightI > curHeight && heightI >= last height in list)
                update curHeight
                count how much water it can trap
            if(heightI < curHeight)
                curHeight = heightI
                append [idxI, heightI] in list
        */
        int n = height.size();
        int curHeight = 0;
        int startIdx = -1;
        int ans = 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < n; i ++){
            if(height[i] != 0) {
                curHeight = height[i];
                startIdx = i;
                st.push({startIdx, curHeight}); //idxI, height
                break;
            }
        }
        if(curHeight == 0) return 0;

        for(int i = startIdx + 1; i < n; i ++){
            int heightI = height[i];
            if(heightI < curHeight){
                st.push({i, heightI}); // Idx, height
                curHeight = heightI;
            }else{
                while(!st.empty()){
                    pair<int, int> prevBar = st.top();
                    if(prevBar.second >= heightI){
                        ans += (heightI - curHeight) * (i - prevBar.first - 1);
                        curHeight = heightI;
                        st.push({i, heightI});
                        break;
                    }else{
                        ans += (prevBar.second - curHeight) * (i - prevBar.first - 1);
                        st.pop();
                        curHeight = prevBar.second;
                    }
                }
                if(st.empty()){
                    st.push({i, heightI});
                    curHeight = heightI;
                }
            }
        }
        return ans;
    }
};