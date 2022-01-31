class Solution {
public:
    // Multisource BFS
    int visited[250][250];
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        memset(visited, 0, sizeof(visited));
        int m = rooms.size();
        int n = rooms[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(rooms[i][j] == 0){
                    q.push(vector<int>{i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                auto curr = q.front();
                q.pop();
                for(auto direc : directions){
                    int x = curr[0] + direc[0];
                    int y = curr[1] + direc[1];
                    if(x >= 0 && x < m &&  y >= 0 && y < n && rooms[x][y] == INT_MAX && visited[x][y] == 0){
                        visited[x][y] = 1;
                        rooms[x][y] = res + 1;
                        q.push(vector<int>{x, y});
                    }
                }
            }
            res++;
        }
    }
};