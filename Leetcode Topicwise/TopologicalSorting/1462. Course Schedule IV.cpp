https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int src, int dst, vector<int> &visited){
        if(visited[src])
            return false;
        if(src == dst)
            return true;
        visited[src] = 1;
        for(auto v : adj[src]){
            if(dfs(adj, v, dst, visited))
                return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        int n = numCourses;
        vector<bool> res;
        for(int i = 0; i<queries.size(); i++){
            int src = queries[i][0];
            int dst = queries[i][1];
            vector<int> visited(n, 0);
            bool ans = dfs(adj, src, dst, visited);
            res.push_back(ans);
        }
        return res;
    }
};