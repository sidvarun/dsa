https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Bellman ford (Accepted)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<int> temp;
        for(int i = 0; i<=k; i++){
            temp = dist;
            for(auto edge : flights){
                int from = edge[0];
                int to = edge[1];
                int price = edge[2];
                if(dist[from] == INT_MAX)
                    continue;
                if(temp[to] > dist[from] + price)
                    temp[to] = dist[from] + price;
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
/**********************************************************************/
// BFS giving TLE 46/49 passed
class Solution {
public:
    int bfs(vector<pair<int, int>> graph[], int src, int dst, int k) {
        queue <pair<int, int>> q;
        for (auto p : graph[src]) {
            q.push(p);
        }
        int ans = INT_MAX;
        while (!q.empty()) {
            int sz = q.size();
            k--;
            if (k < -1) break;
            for (int s=0; s<sz; s++) {
                auto node = q.front();
                q.pop();
                if (node.first == dst)
                    ans = min(ans, node.second);
                for (auto child : graph[node.first]) {
                    if(child.second + node.second > ans) continue;
                    child.second += node.second;
                    q.push(child);
                }
            }
        }
        return ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto &it : flights)
            adj[it[0]].push_back({it[1], it[2]});
        int ans = bfs(adj, src, dst, k);
        return ans == INT_MAX ? -1 : ans;
    }
};