class Solution {
public:
    int res;
    int m;
    int n;
    int dfs(int i, int j, vector<vector<int>> directions, vector<vector<int>>& graph){
        if(i >= m || i < 0 || j < 0 || j >= n)
            return 0;
        graph[i][j] = 0;
        int area = 0;
        bool val = false;
        for(auto direc : directions){
            int x = i + direc[0];
            int y = j + direc[1];
            if(x < m && x >= 0 && y >= 0 && y < n && graph[x][y] == 1){
                val = true;
                area += dfs(x, y, directions, graph);
            }
        }
        if(val)
            return area + 1;
        return 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& graph) {
        res = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        m = graph.size();
        n = graph[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(graph[i][j] == 1)
                    res = max(res, dfs(i, j, directions, graph));
            }
        }
        return res;
    }
};