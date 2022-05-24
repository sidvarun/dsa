class StockSpanner {
public:
    stack<pair<int, int>> prices;
    int day;
    StockSpanner() {
        day = 0;
    }
    
    int next(int price) {
        while(!prices.empty() && prices.top().first <= price)
            prices.pop();
        day++;
        int res = day;
        if(!prices.empty())
            res = day - prices.top().second;
        prices.push({price, day});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */