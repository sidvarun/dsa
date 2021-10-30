https://leetcode.com/problems/minimum-height-trees/

https://leetcode.com/problems/minimum-height-trees/discuss/952374/Python-3-approaches-Detailed-Explanation-and-Visuals

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> layer;
        if(n == 1){
            layer.push_back(0);
            return layer;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> q;
        vector<int> indegree(n, 0);
        for(int i = 0; i<n; i++)
            for(auto u : adj[i])
                indegree[u]++;
        for(int i = 0; i<n; i++)
            if(indegree[i] == 1)
                q.push(i);
        while(!q.empty()){
            int s = q.size();
            layer = {};
            for(int i = 0; i<s; i++){
                int u = q.front();
                layer.push_back(u);
                q.pop();
                for(auto v : adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1)
                    q.push(v);
                }
            }
        }
        return layer;
    }
};