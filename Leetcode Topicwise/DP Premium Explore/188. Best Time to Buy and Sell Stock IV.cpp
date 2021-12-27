class Solution {
public:
    int memo[1001][101][2];
    int dp(int i, int transLeft, int state, vector<int> prices, int k){
        if(i == prices.size() || transLeft == 0)
            return 0;
        if(memo[i][transLeft][state] != -1)
            return memo[i][transLeft][state];
        if(state == 0){
            int profitOnBuying = dp(i + 1, transLeft, 1, prices, k) - prices[i];
            memo[i][transLeft][state] = max(profitOnBuying, dp(i + 1, transLeft, 0, prices, k));
        }
        else if(state == 1){
            int profitOnSelling = dp(i + 1, transLeft - 1, 0, prices, k) + prices[i];
            memo[i][transLeft][state] = max(profitOnSelling, dp(i + 1, transLeft, 1, prices, k));
        }
        return memo[i][transLeft][state];
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return dp(0, k, 0, prices, k);
    }
};