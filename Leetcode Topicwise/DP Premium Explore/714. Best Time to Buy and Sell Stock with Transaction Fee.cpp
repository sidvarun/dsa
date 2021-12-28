class Solution {
public:
    int memo[50001][2];
    int dp(int i, int holding, vector<int>& prices, int fee){
        if(i == prices.size())
            return 0;
        if(memo[i][holding] != -1)
            return memo[i][holding];
        
        // not holding
        if(holding == 0)
            memo[i][holding] = max(dp(i + 1, 0, prices, fee), dp(i + 1, 1, prices, fee) - prices[i]);
        
        // holding
        if(holding == 1)
            memo[i][holding] = max(dp(i + 1, 1, prices, fee), dp(i + 1, 0, prices, fee) + prices[i] - fee);
        return memo[i][holding];
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, prices, fee);
    }
};