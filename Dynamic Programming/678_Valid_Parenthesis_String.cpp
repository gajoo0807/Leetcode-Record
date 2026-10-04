class Solution {
public:
    bool checkValidString(string s) {
        deque<int> starCnt;
        stack<int> st;
        int n = s.size();

        for(int i = 0; i < n; i ++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.empty()){
                    if(starCnt.size() == 0) return false;
                    else starCnt.pop_front();
                }else st.pop();
            }else{
                starCnt.push_back(i);
            }
        }

        if(st.size() > starCnt.size()) return false;
        int starIdx = starCnt.size() - 1;
        while(!st.empty()){
            int leftIdx = st.top();
            st.pop();
            int starIdx = starCnt.back();
            starCnt.pop_back();
            if(leftIdx > starIdx) return false;
        }
        return true;
    }
};