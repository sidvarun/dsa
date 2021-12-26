class Solution {
public:
    int memo[10001];
    int dp(vector<int>& coins, int amount){
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if(memo[amount] != 0)
            return memo[amount];
        int subres = INT_MAX;
        for(auto coin : coins){
            if(coin <= amount){
                int temp = dp(coins, amount - coin);
                if(temp >= 0 && temp < subres)
                    subres = 1 + temp;
            }
        }
        memo[amount] = subres != INT_MAX ? subres : -1;
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1)
            return 0;
        memset(memo, 0, sizeof(memo));
        return dp(coins, amount);
    }
};