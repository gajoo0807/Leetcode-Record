class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> ansEachRows(numRows, "");
        int n = s.size(), idx = 0, dir = 1;

        for(int i = 0; i < n; i ++){
            ansEachRows[idx].push_back(s[i]);
            if(idx == 0) dir = 1;
            else if(idx == numRows-1) dir = -1;

            idx += dir;
        }
        string result = "";
        for(string& ans: ansEachRows){
            result += ans;
        }
        return result;
    }
};