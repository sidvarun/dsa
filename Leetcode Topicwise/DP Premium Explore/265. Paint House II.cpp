class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        int dp[n][k];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<k; j++){
                if(i == 0)
                    dp[i][j] = costs[i][j];
                else{
                    int temp = INT_MAX;
                    for(int m = 0; m<k; m++){
                        if(m != j)
                            temp = min(temp, costs[i][j] + dp[i - 1][m]);
                    }
                    dp[i][j] = temp;
                }
            }
        }
        int res = INT_MAX;
        for(int j = 0; j<k; j++)
            res = min(res, dp[n - 1][j]);
        return res;
    }
};