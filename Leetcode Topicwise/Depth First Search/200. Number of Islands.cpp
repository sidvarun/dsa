class Solution {
public:
    int visited[300][300];
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& directions){
        visited[i][j] = 1;
        for(auto direc : directions){
            int x = i + direc[0];
            int y = j + direc[1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && visited[x][y] == 0)
                dfs(grid, x, y, directions);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        memset(visited, 0, sizeof(visited));
        int res = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(grid, i, j, directions);
                    res++;
                }
            }
        }
        return res;
    }
};