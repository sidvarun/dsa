class Solution {
public:
    vector<vector<int>> res;
    vector<int> visited;
    void dfs(vector<vector<int>> &graph, int src, int dst, vector<int> path){
        
        if(src == dst){
            path.push_back(src);
            res.push_back(path);
            return;
        }
        
        visited[src] = 1;
        
        path.push_back(src);
        
        for(auto u : graph[src]){
            
            if(!visited[u])
                dfs(graph, u, dst, path);

        }
        
        visited[src] = 0;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        visited.resize(n, 0);
        
        vector<int> path;
        
        dfs(graph, 0, n - 1, path);
        
        return res;
    }
};