class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(q.size() == 0 && fresh == 0)
            return 0;
        int res = 0;
        while(!q.empty()){
            int count = q.size();
            for(int i = 0; i<count; i++){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                for(auto dir : directions){
                    int u = x + dir[0];
                    int v = y + dir[1];
                    if(u >= 0 && u < m && v >= 0 && v < n && grid[u][v] == 1){
                        grid[u][v] = 2;
                        q.push({u, v});
                        fresh--;
                    }
                }
            }
            res++;
        }
        return fresh == 0 ? res - 1 : -1;
    }
};


