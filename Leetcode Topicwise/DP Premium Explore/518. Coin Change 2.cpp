class Solution {
public:
    int memo[5001][300];
    int dp(int a, int i, int amount, vector<int>& coins){
        if(a > amount)
            return 0;
        if(a == amount)
            return 1;
        if(i == coins.size())
            return 0;
        if(memo[a][i] != -1)
            return memo[a][i];
        memo[a][i] = dp(a + coins[i], i, amount, coins) +  dp(a, i + 1, amount, coins);
        return memo[a][i];
    }
    int change(int amount, vector<int>& coins) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, amount, coins);
    }
};