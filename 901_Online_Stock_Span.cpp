class StockSpanner {
private:
    stack<pair<int, int>> s; // stock price, span of the stock price
public:
    StockSpanner() {
        s.push({INT_MAX, 0});
    }
    
    int next(int price) {
        int curSpan = 1;
        while (price >= s.top().first) {
            curSpan += s.top().second;
            s.pop();
        }
        s.push({price, curSpan});
        return curSpan;
    }
};