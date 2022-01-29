class Solution {
public:
    int memo[57];
    int dp(int n){
        if(n == 1)
            return 1;
        if(memo[n] != -1)
            return memo[n];
        int temp = -1;
        for(int i = 1; i <= n - 1; i++)
            temp = max(temp, max(i * (n - i), i * dp(n - i)));
        return memo[n] = temp;
    }
    int integerBreak(int n) {
        memset(memo, -1, sizeof(memo));
        return dp(n);
    }
};