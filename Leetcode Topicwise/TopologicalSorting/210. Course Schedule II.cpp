https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> impossible;
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        vector<int> visited(numCourses, 0);
        queue<int> q;
        int n = numCourses;
        vector<int> indegree(n, 0);
        for(int i = 0; i<n; i++)
            for(auto u : adj[i])
                indegree[u]++;
        for(int i = 0; i<n; i++)
            if(indegree[i] == 0)
                q.push(i);
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            count++;
            for(auto i : adj[u]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return count == numCourses ? res : impossible;
    }
};
