class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<vector<int>>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back(vector<int>{j, dist});
                adj[j].push_back(vector<int>{i, dist});;
            }
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_set<int> visited;
        pq.push({0, 0});
        int cost = 0;
        while(visited.size() != n){
            auto curr = pq.top();
            pq.pop();
            if(visited.find(curr[1]) != visited.end())
                continue;
            count++;
            visited.insert(curr[1]);
            cost += curr[0];
            for(auto j : adj[curr[1]]){
                if(visited.find(j[0]) == visited.end())
                    pq.push(vector<int>{j[1], j[0]});
            }
        }
        return cost;
    }
};

/******************************************************************/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j)
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            while (visited[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};