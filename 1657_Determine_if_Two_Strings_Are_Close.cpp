class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        if(n != word2.size()) return false;

        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);

        for(int i = 0; i < n; i++){
            vec1[word1[i] - 'a'] ++;
            vec2[word2[i] - 'a'] ++;
        }

        for(int i = 0; i < 26; i ++){
            if((vec1[i] == 0 && vec2[i] != 0) ||(vec1[i] != 0 && vec2[i] == 0))
                return false;
        }

        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());

        return std::equal(vec1.begin(), vec1.end(), vec2.begin());
    }
};