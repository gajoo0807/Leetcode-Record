class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3;  // 計算所有可能的 happy string 數量
        for (int i = 1; i < n; i++) total *= 2;

        string ans = "";
        if (k > total) return ans; // 如果 k 超過範圍，回傳空字串

        char c;
        if (k <= total / 3) {
            c = 'a';
        } else if (k > total / 3 && k <= total / 3 * 2) {
            c = 'b';
            k -= total / 3; // 調整 k，因為我們已經選了 'b'
        } else {
            c = 'c';
            k -= (total / 3 * 2); // 調整 k，因為我們已經選了 'c'
        }

        ans += c;

        total /= 3; // 剩下的字串數變小，每次選擇後可能性減半

        // 逐步決定後面的字母
        for (int i = 1; i < n; i++) {
            total /= 2; // 每次選擇後剩下的 happy strings 數量減半
            if (k <= total) { 
                if (ans.back() == 'a') ans += 'b';
                else ans += 'a';
            } else {
                k -= total; // 移動到下一半的區間
                if (ans.back() == 'a') ans += 'c';
                else if (ans.back() == 'b') ans += 'c';
                else ans += 'b';
            }
        }

        return ans;
    }
};