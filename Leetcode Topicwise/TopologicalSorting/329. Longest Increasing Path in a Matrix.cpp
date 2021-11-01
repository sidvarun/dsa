https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

https://www.youtube.com/watch?v=uLjO2LUlLN4&ab_channel=MichaelMuinos

class Solution {
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int m, int n, vector<vector<int>> &directions){
        if(dp[i][j] != 0)
            return dp[i][j];
        int lpath = 0;
        for(auto dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]){
                int longest = dfs(matrix, dp, x, y, m, n, directions);
                lpath = max(lpath, longest);
            }
        }
        dp[i][j] = 1 + lpath;
        return dp[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int longest =  dfs(matrix, dp, i, j, m, n, directions);
                res = max(res, longest);
            }
        }
        return res;
    }
};
