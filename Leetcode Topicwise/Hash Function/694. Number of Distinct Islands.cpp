https://leetcode.com/problems/number-of-distinct-islands/

https://www.youtube.com/watch?v=c1ZxUOHlulo

class Solution {
public:
    string computePath(vector<vector<int>> &grid, int i, int j, int m, int n, string direction){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return "O";
        grid[i][j] = 0;
        string left = computePath(grid, i, j - 1, m, n, "L");
        string right = computePath(grid, i, j + 1, m, n, "R");
        string up = computePath(grid, i - 1, j, m, n, "U");
        string down = computePath(grid, i + 1, j, m, n, "D");
        return direction + left + right + up + down;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> distinct;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    string path = computePath(grid, i, j, m, n, "X");
                    distinct.insert(path);
                }
            }
        }
        return distinct.size();
    }
};