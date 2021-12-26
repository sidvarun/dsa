class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        int res = INT_MIN;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};