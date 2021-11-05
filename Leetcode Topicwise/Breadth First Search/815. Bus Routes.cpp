https://leetcode.com/problems/bus-routes/solution/

/*
Intuition

Instead of thinking of the stops as nodes (of a graph), think of the buses as nodes. We want to take the least number of buses, which is a shortest path problem, conducive to using a breadth-first search.

Algorithm

We perform a breadth first search on bus numbers. When we start at S, originally we might be able to board many buses, and if we end at T we may have many targets for our goal state.

One difficulty is to efficiently decide whether two buses are connected by an edge. They are connected if they share at least one bus stop. Whether two lists share a common value can be done by set intersection (HashSet), or by sorting each list and using a two pointer approach.
*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        vector<unordered_set<int>> buses;
        for(int i = 0; i<routes.size(); i++){
            unordered_set<int> s;
            for(auto x : routes[i])
                s.insert(x);
            buses.push_back(s);
        }
        
        queue<int> q;
        unordered_set<int> visited;
        for(int i = 0; i<buses.size(); i++){
            unordered_set<int> s = buses[i];
            if(s.find(source) != s.end()){
                q.push(i);
                visited.insert(i);
            }
        }
        
        if(q.empty())
            return -1;
        
        int res = 1;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                int curr = q.front();
                q.pop();
                if(buses[curr].find(target) != buses[curr].end())
                    return res;
                for(int i = 0; i<buses.size(); i++){
                    
                    if(visited.find(i) == visited.end()){
                        unordered_set<int> c;
                        for (int element : buses[curr]) {
                          if (buses[i].count(element) > 0) {
                            c.insert(element);
                          }
                        }
                        if(c.size() > 0){
                            visited.insert(i);
                            q.push(i);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
