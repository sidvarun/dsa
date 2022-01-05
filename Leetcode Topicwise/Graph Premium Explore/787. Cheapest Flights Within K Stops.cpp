class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        vector<int> distPrev;
        vector<int> distCurr(n, INT_MAX);
        distCurr[src] = 0;
        for(int i = 1; i <= k + 1; i++){
            distPrev = distCurr;
            for(int v = 0; v<n; v++){
                for(auto u : adj[v] ){
                    if(distPrev[v] == INT_MAX)
                        continue;
                    if(distCurr[u[0]] > distPrev[v] + u[1])
                        distCurr[u[0]] = distPrev[v] + u[1];
                }
            }
        }
        return distCurr[dst] == INT_MAX ? -1 : distCurr[dst];
    }
};