class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                dp[i][j] = INT_MAX;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                
                if(i == 0)
                    dp[i][j] = matrix[i][j];
                
                if(i - 1 >= 0 && j + 1 < n)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
                
                if(i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
                
                if(i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
            }
        }
        int res = INT_MAX;
        for(int j = 0; j<n; j++)
            res = min(res, dp[n - 1][j]);
        return res;
    }
};