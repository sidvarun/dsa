class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto time : times)
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[k - 1], k - 1});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int u = curr.second;
            for(auto v : adj[u]){
                if(dist[v[0]] > d + v[1]){
                    dist[v[0]] = d + v[1];
                    pq.push({dist[v[0]], v[0]});
                }
            }
        }
        int res = 0;
        for(int i = 0; i<dist.size(); i++)
            res = max(res, dist[i]);
        return res == INT_MAX ? -1 : res;
    }
};

