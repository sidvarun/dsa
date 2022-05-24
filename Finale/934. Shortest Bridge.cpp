class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<int>> &grid, int s, vector<vector<int>>& directions){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == s)
            return;
        
        grid[i][j] = s;
        
        for(auto dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(x, y, grid, s, directions);
        }
    }
    
    int shortestBridge(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, 2, directions);
                    i = m;
                    break;
                }
            }
        }
        
        queue<vector<int>> q;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push(vector<int>{i, j});
            }
        }
        
        int res = 0;
        
        while(!q.empty()){
            
            int c = q.size();
            
            for(int i = 0; i<c; i++){
                auto curr = q.front();
                q.pop();
                int x = curr[0];
                int y = curr[1];
                
                if(grid[x][y] == 4)
                    continue;
                
                if(grid[x][y] == 1)
                    return res - 1;
                
                grid[x][y] = 4;
                
                for(auto dir : directions){
                    int p = x + dir[0];
                    int t = y + dir[1];
                    if(p < 0 || p >= m || t < 0 || t >= n)
                        continue;
                    
                    q.push(vector<int>{p, t});
                }
            }
            res++;
        }
        
        return res;
    }
};