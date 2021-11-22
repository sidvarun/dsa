class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = INT_MIN;
        int minm = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] >= minm)
                res = max(res, prices[i] - minm);
            else if(prices[i] < minm)
                minm = prices[i];
        }
        return res == INT_MIN ? 0 : res;
    }
};
