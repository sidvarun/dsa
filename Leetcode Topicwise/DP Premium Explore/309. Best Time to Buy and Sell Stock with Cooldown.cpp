class Solution {
public:
    int memo[5001][2];
    int dp(int i, int state, vector<int> prices){
        if(i >= prices.size())
            return 0;
        if(memo[i][state] != -1)
            return memo[i][state];
        if(state == 0){
            int profitOnBuying = dp(i + 1, 1, prices) - prices[i];
            memo[i][state] = max(profitOnBuying, dp(i + 1, 0, prices));
        }
        else if(state == 1){
            int profitOnSelling = dp(i + 2, 0, prices) + prices[i];
            memo[i][state] = max(profitOnSelling, dp(i + 1, 1, prices));
        }
        return memo[i][state];
    }
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, prices);
    }
};