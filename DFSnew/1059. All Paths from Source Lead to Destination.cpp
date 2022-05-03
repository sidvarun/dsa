class Solution {
public:
    /*
        white(0) - unvisited
        gray(1) - currently in dfs stack
        black(2) - processing completed
        
    */
    
    vector<int> visited; 
    vector<vector<int>> adj;
    int n;
    
    bool dfs(int source, int destination){
        
        if(adj[source].size() == 0 && source != destination)
            return false;
        
        visited[source] = 1;
        
        for(auto u : adj[source]){
            
            if(visited[u] == 1)
                return false;
            
            if(visited[u] == 0 && !dfs(u, destination))
                return false;
        }
        
        visited[source] = 2;
        
        return true;
    }
    
    bool leadsToDestination(int V, vector<vector<int>>& edges, int source, int destination) {
        
        n = V;
        visited.resize(n, 0);
        adj.resize(n);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        return dfs(source, destination);
    }
};