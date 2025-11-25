class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        vector<int> reminder_vec(k, 0);
        int n = 1;
        int reminder = 1 % k;
        while(n < k){
            if(reminder == 0) return n;
            if(reminder_vec[reminder] == 1) return -1;
            reminder_vec[reminder] = 1;
            reminder = (reminder * 10 + 1) % k;
            n ++;
        }
        return n;
    }
};