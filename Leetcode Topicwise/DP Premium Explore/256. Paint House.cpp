class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int dp[n][3];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<3; j++){
                if(i == 0)
                    dp[i][j] = costs[i][j];
                else{
                    if(j == 0)
                        dp[i][j] = costs[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
                    if(j == 1)
                         dp[i][j] = costs[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
                    if(j == 2)
                         dp[i][j] = costs[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
                }
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};