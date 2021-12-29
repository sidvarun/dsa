class Solution {
public:
    // memo[n][target]
    int memo[30][1000];
    int dp(int i, int target, int k, int n){
        if(i == n && target == 0)
            return 1;
        if(i == n || target < 0)
            return 0;
        if(memo[i][target] != -1)
            return memo[i][target];
        int res = 0;
        for(int j = 1; j<=k; j++)
            res = (res % 1000000007 + dp(i + 1, target - j, k, n) % 1000000007) % 1000000007;
        memo[i][target] = res;
        return memo[i][target] % 1000000007;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(memo, -1, sizeof(memo));
        return dp(0, target, k, n);
    }
};