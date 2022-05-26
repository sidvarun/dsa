class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>> adj(n + 1);
        
        for(auto time : times)
            adj[time[0]].push_back(vector<int>{time[1], time[2]});
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int res = 0;
        unordered_set<int> visited;
        
        pq.push(vector<int>{0, k});
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int w1 = curr[0];
            int n1 = curr[1];
            
            if(visited.find(n1) != visited.end())
                continue;
            
            visited.insert(n1);
            
            res = max(res, w1);
            
            for(auto neighbour : adj[n1]){
                int n2 = neighbour[0];
                int w2 = neighbour[1];
                if(visited.find(n2) == visited.end())
                    pq.push(vector<int>{w2 + w1, n2});
            }
        }
        return visited.size() == n ? res : -1;
    }
};