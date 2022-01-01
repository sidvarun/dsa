class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<vector<int>>& graph, int start, int end, vector<int>& visited, vector<int> path){
        visited[start] = 1;
        
        if(start == end){
            res.push_back(path);
        }
        
        for(auto v : graph[start]){
            if(!visited[v]){
                path.push_back(v);
                dfs(graph, v, end, visited, path);
                path.pop_back();
            }
        }
        visited[start] = 0;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> visited(graph.size(), 0);
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, n - 1, visited, path);
        return res;
    }
};