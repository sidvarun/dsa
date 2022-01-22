https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126938/Short-and-Easy-w-Explanation-and-diagrams-or-Simple-Graph-traversals-DFS-and-BFS

class Solution {
public:
    int m, n;
    vector<vector<int>> pac, atl;
    vector<vector<int>> res;
    void dfs(int row, int col, int prevHeight, vector<vector<int>>& visited, vector<vector<int>>& heights){
        if(row < 0 || row == m || col < 0 || col == n || visited[row][col] == 1 || heights[row][col]  < prevHeight)
            return;
        visited[row][col] = 1;
        dfs(row + 1, col, heights[row][col], visited, heights);
        dfs(row - 1, col, heights[row][col], visited, heights);
        dfs(row, col + 1, heights[row][col], visited, heights);
        dfs(row, col - 1, heights[row][col], visited, heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        atl = pac = vector<vector<int> >(m, vector<int>(n, 0));
        for(int col = 0; col<n; col++){
            dfs(0, col, heights[0][col], pac, heights);
            dfs(m - 1, col, heights[m - 1][col], atl, heights);
        }

        for(int row = 0; row<m; row++){
            dfs(row, 0, heights[row][0], pac, heights);
            dfs(row, n - 1, heights[row][n - 1], atl, heights);
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac[i][j] == 1 && atl[i][j] == 1){
                    res.push_back(vector<int> {i, j});
                }
            }
        }
        
        return res;        
    }
};


