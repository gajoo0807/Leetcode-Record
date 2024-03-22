class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // purchase or sell or do nothing

        int n = prices.size();

        int purchase = -(prices[0]), sell = 0;

        for(int i = 1; i < n; i ++){
            purchase = max(sell - prices[i], purchase);
            sell = max(purchase + prices[i] - fee, sell);
        }
        return sell;
    }
};