class Solution {
public:
    int memo[50][100000];
    int dp(int n, int k){
        if(n == 1)
            return k;
        if(n == 2)
            return k * k;
        if(memo[n][k] != -1)
            return memo[n][k];
        memo[n][k] = (k - 1) * (dp(n - 1, k) + dp(n - 2, k));
        return memo[n][k];
    }
    int numWays(int n, int k) {
        memset(memo, -1, sizeof(memo));
        return dp(n, k);
    }
};