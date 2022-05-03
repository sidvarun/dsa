class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    int n;
    
    bool dfs(int s, int d){
        
        if(s == d)
            return true;
        
        visited[s] = 1;
        
        
        for(auto u : adj[s]){
            if(!visited[u] && dfs(u, d))
                return true;
        }
                
        return false;
    }
    
    bool validPath(int V, vector<vector<int>>& edges, int source, int destination) {
        n = V;
        adj.resize(n);
        visited.resize(n, 0);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        return dfs(source, destination);

    }
};