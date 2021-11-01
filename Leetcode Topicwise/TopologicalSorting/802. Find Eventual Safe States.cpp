https://leetcode.com/problems/find-eventual-safe-states/

// using bfs

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> outdegree(n, 0);
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<n; i++){
            for(auto j : graph[i])
                m[j].push_back(i);
        }
        for(int i = 0; i<graph.size(); i++)
            outdegree[i] = graph[i].size();
        queue<int> q;
        for(int i = 0; i<n; i++)
            if(outdegree[i] == 0)
                q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto i : m[u]){
                outdegree[i]--;
                if(outdegree[i] == 0)
                    q.push(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// using dfs

