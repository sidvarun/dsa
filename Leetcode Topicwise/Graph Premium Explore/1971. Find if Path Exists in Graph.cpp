class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int start, int end, vector<int>& visited){
        visited[start] = 1;
        if(start == end)
            return true;
        for(auto v : adj[start]){
            if(!visited[v] && dfs(adj, v, end, visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        return dfs(adj, start, end, visited);
    }
};