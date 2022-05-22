class Solution {
public:
    vector<int> res;
    
    unordered_map<int, bool> safe;

    bool dfs(int i, vector<vector<int>>& graph){
        
        if(safe.find(i) != safe.end())
            return safe[i];
        
        safe[i] = false;
        
        for(auto j : graph[i]){
            if(!dfs(j, graph))
                return false;
        }
        
        return safe[i] = true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        for(int i = 0; i<n; i++){
            if(dfs(i, graph))
                res.push_back(i);
        }
        
        return res;
    }
};