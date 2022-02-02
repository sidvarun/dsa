class Solution {
public:
    int visited[50][50];
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        memset(visited, 0, sizeof(visited));
        pq.push(vector<int>{grid[0][0], 0, 0});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            // if(visited[curr[1]][curr[2]] == 1)
            //     continue;
            // visited[curr[1]][curr[2]] = 1;
            if(curr[1] == n - 1 && curr[2] == n - 1)
                return curr[0];
            for(auto direc : directions){
                int x = curr[1] + direc[0];
                int y = curr[2] + direc[1];
                
                if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] != 1){
                    pq.push(vector<int>{max(grid[x][y], curr[0]), x, y});
                    visited[x][y] = 1;
                }
            }
        }
        return -1;
    }
};