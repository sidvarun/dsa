https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/discuss/1417576/C%2B%2BPython-Dijkstra-Clean-and-Concise

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads){
        long long res;
        vector<vector<vector<long long>>> graph(n);
        for(long long i = 0; i<roads.size(); i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;
        vector<long long> ways(n, 1);
        ways[0] = 1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({dist[0], 0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            long long u = curr.second;
            long long d = curr.first;
            if(d > dist[u])
                continue;
            for(auto v : graph[u]){
                if(d + v[1] < dist[v[0]]){
                    dist[v[0]] = d + v[1];
                    pq.push({dist[v[0]], v[0]});
                    ways[v[0]] = ways[u];
                }
                else if(d + v[1] == dist[v[0]]){
                    ways[v[0]] = (ways[u] + ways[v[0]])%1000000007;
                }
            }         
        }
        return ways[n - 1];
    }
};
