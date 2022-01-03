class Solution {
public:
    int visited[100][100];
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        memset(visited, 0, sizeof(visited));
        vector<pair<int, int>> directions = {{1, 1}, {0, 1}, {1, 0}, {-1, -1}, {0, -1}, {-1, 0}, {1, -1}, {-1, 1}};
        int n = grid.size();
        if(n == 1)
            return grid[0][0] == 0 ? 1 : -1;
        queue<pair<int, int>> q;
        if(grid[0][0] == 0)
            q.push({0, 0});
        int res = 1;
        while(!q.empty()){
            int c = q.size();
            for(int count = 0; count < c; count++){
                auto curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();
                for(auto direc : directions){
                    int x = i + direc.first;
                    int y = j + direc.second;
                    if(x == n - 1 && y == n - 1 && grid[x][y] == 0)
                        return res + 1;
                    if(x < n && y < n && x >= 0 && y >= 0 && !visited[x][y] && grid[x][y] == 0){
                        q.push({x, y});
                        visited[x][y] = 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};