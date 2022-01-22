class Solution {
public:
    unordered_set<int> visited;
    bool dfs(int i, int prev, vector<vector<int>>& adj){
        if(visited.find(i) != visited.end())
            return false;
        visited.insert(i);
        for(auto j : adj[i]){
            if(j == prev)
                continue;
            if(dfs(j, i, adj) == false)
                return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, adj) && visited.size() == n;
    }
};