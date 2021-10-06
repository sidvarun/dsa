 https://leetcode.com/problems/network-delay-time/submissions/

/*
    Firstly, from the given input vector, we have to make the adjacency list for the required directed weighted graph.

    A corner condition: If node k has no outgoing connections, then it is impossible for signal to reach to all nodes, we return -1 in this case.

    Approach : Dijkstra's Shortest Path Algorithm (99.61% faster)
    Here, our priority is to reach to all nodes anyhow. So, we calculate the minimum distance to all other nodes from given "k" node. For getting minimum distance every time, we make a minimum heap using C++ STL priority queue.

    Once we have visited all feasible nodes from given "k" node, we have the minimum distances of the nodes which we have visited from "k". So now, our answer would be the maximum distance in these all distances.

    If our maximum distance is INT_MAX, that means we have not visited some nodes (hence distance vector was initialized with INT_MAX in starting). So we will return -1.
    Else we will return maximum distance.
*/
   
   
class Solution{
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            //dist set everyone to inf
            vector<int> dist(n+1,INT_MAX);
            dist[k]=0;

            //convert the graph into adj list
            vector<vector<pair<int,int>>> g(n+1);
            for(auto e: times){
                g[e[0]].push_back({e[1],e[2]});
            }

            //insert source in minHeap and set it's dist=0
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({0,k}); //{weight,node}

            //no need to track processed nodes(like we do in O(V^2) implementation), if doing this way
            while(!pq.empty()){
                auto p =pq.top();
                pq.pop();
                int u = p.second;
                for(auto nbr: g[u]){
                    int v = nbr.first, w = nbr.second;
                    if(dist[v] > dist[u]+w){
                        dist[v] = dist[u]+w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int res= 0;
            for(int i=1; i<=n; i++){
                res = max(dist[i],res);
            }
            return res==INT_MAX ? -1 : res;
        }   
};