//Breadth First Search
class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    void BFS(vector<int> adj[], int s, bool visited[],vector<int> &res) 
    { 	
        queue<int>  q;
    	visited[s] = true; 
    	q.push(s); 
    	while(q.empty()==false) 
    	{ 
    		int u = q.front(); 
    		q.pop();
    		res.push_back(u); 
    		 
    		for(int v:adj[u]){
    		    if(visited[v]==false){
    		        visited[v]=true;
    		        q.push(v);
    		    }
    		} 
    	} 
    }
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> res;
	    bool visited[V]; 
    	for(int i = 0;i<V; i++) 
    		visited[i] = false;
    		
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                BFS(adj,i,visited,res);
        }
        return res;
	}
};
/*********************************************************************************************************************/

// Dept First Search
class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void DFSRec(vector<int> adj[], int s, bool visited[],vector<int> &res){ 	
        visited[s]=true;
        res.push_back(s);
        
        for(int u:adj[s]){
            if(visited[u]==false)
                DFSRec(adj,u,visited,res);
        }
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> res;
    	bool visited[V]; 
    	for(int i = 0;i<V; i++) 
    		visited[i] = false;
    		
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                DFSRec(adj,i,visited,res);
        }
        return res;
	}
};
/****************************************************************************************************************************/

//Detect  Cycle in Undirected Graph
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool DFSRec(vector<int> adj[], int s,bool visited[], int parent) 
    { 	
        visited[s]=true;
        
        for(int u:adj[s]){
            if(visited[u]==false){
                if(DFSRec(adj,u,visited,s)==true)
                    {return true;}}
            else if(u!=parent)
                {return true;}
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
    	bool visited[V]; 
    	for(int i=0;i<V; i++) 
    		visited[i] = false;
    		
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                if(DFSRec(adj,i,visited,-1)==true)
                    return true;
        }
        return false;
	}
};
/*******************************************************************************************************************************/
//Detect cycle in a Directed Graph
// using DFS
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool DFSRec(vector<int> adj[], int s,bool visited[], bool recSt[]) 
    { 	
        visited[s]=true;
        recSt[s]=true;
        
        for(int u:adj[s]){
            if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)
                    {return true;}
            else if(recSt[u]==true)
                {return true;}
        }
        recSt[s]=false;
        return false;
    }
	bool isCyclic(int V, vector<int>adj[])
	{
    	bool visited[V]; 
    	for(int i=0;i<V; i++) 
    		visited[i] = false;
    	bool recSt[V]; 
    	for(int i=0;i<V; i++) 
    		recSt[i] = false;
    		
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                if(DFSRec(adj,i,visited,recSt)==true)
                    return true;
        }
        return false;
	}
};

// using BFS
class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
};
/************************************************************************************************************************/
//Topological sort - https://practice.geeksforgeeks.org/problems/topological-sort/1
//Using BFS
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	        vector<int> in_degree(V, 0); 
            vector<int> res;
            for (int u = 0; u < V; u++) { 
                for (int x:adj[u]) 
                    in_degree[x]++; 
            } 
            queue<int> q; 
            for (int i = 0; i < V; i++) 
                if (in_degree[i] == 0) 
                    q.push(i); 
                    
            while (!q.empty()) { 
                int u = q.front(); 
                q.pop(); 
                res.push_back(u); 
         
                for (int x: adj[u]) 
                    if (--in_degree[x] == 0) 
                        q.push(x);
            } 
            return res;
	}
// Using DFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int u, stack<int> &st, vector<int> adj[], bool visited[]){
	    visited[u] = true;
	    for(auto v : adj[u]){
	        if(visited[v] == false)
	            dfs(v, st, adj, visited);
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    bool visited[V] = {false};
	    stack<int> st;
	    vector<int> res;
	    for(int i = 0; i<V; i++){
	        if(visited[i] == false)
	            dfs(i, st, adj, visited);
	    }
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};
/**********************************************************************************************/
//Minimum Steps required by a knight to reach the target
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isInside(int x, int y, int N)
    {
        if (x >= 1 && x <= N && y >= 1 && y <= N)
            return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int N)
	{
    	// x and y direction, where a knight can move
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
      
        // queue for storing states of knight in board
        queue<pair<int, pair<int, int> >> q;
      
        // push starting position of knight with 0 distance
        q.push({0,{knightPos[0], knightPos[1]}});
      
        pair<int, pair<int, int> > t;
        int x, y;
        bool visit[N + 1][N + 1];
      
        // make all cell unvisited
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                visit[i][j] = false;
      
        // visit starting state
        visit[knightPos[0]][knightPos[1]] = true;
      
        // loop untill we have one element in queue
        while (!q.empty()) {
            t = q.front();
            q.pop();
      
            // if current cell is equal to target cell,
            // return its distance
            if (t.second.first == targetPos[0] && t.second.second == targetPos[1])
                return t.first;
      
            // loop for all reachable states
            for (int i = 0; i < 8; i++) {
                x = t.second.first + dx[i];
                y = t.second.second + dy[i];
      
                // If reachable state is not yet visited and
                // inside board, push that state into queue
                if (isInside(x, y, N) && !visit[x][y]) {
                    visit[x][y] = true;
                    q.push({t.first + 1,{x, y}});
                }
            }
        }
    

	}
};
//Problematic code(Not workinnf for now)
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int s1 = KnightPos[0] - 1;
	    int s2 = KnightPos[1] - 1;
        int d1 = TargetPos[0] - 1;
	    int d2 = TargetPos[1] - 1;
	    if(s1==d1 && s2==d2)
	        return 0;
	    int x[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	    int y[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    bool visited[N][N]; 
	    int count = 0;
    	for(int i=0;i<N; i++) 
    	   for(int j=0;j<N; j++) 
    		 visited[i][j] = false;
    	queue<pair<int,int>>  q;
    	visited[s1][s2] = true; 
    	q.push({s1,s2}); 
    	while(q.empty()==false) { 
    		pair<int,int> u = q.front(); 
    		q.pop();
    		int ts1=u.first;
    		int ts2=u.second;
    		if(ts1 == d1 && ts2 == d2)
    		    return count;
    		for(int i = 0; i < 8; i++){
    		        if(ts1+x[i] >= 0 && ts1+x[i] < N && ts2+y[i] >= 0 && ts2+y[i] < N && visited[ts1+x[i]][ts2+y[i]] == false){

    		                count++;
    		                visited[ts1+x[i]][ts2+y[i]] = true;
    		                if(ts1+x[i] == d1 && ts2+y[i] == d2)
    		                    return count;
                		    q.push({ts1+x[i], ts2+y[i]});

    		        }
    	    }
    	} 

	}
    /***************************************************************************************************************************/
    // CPP program to check whether we can finish all
// tasks or not from given dependencies.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> > make_graph(int numTasks,
			vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// A DFS based function to check if there is a cycle
// in the directed graph.
bool dfs_cycle(vector<unordered_set<int> >& graph, int node,
			vector<bool>& onpath, vector<bool>& visited)
{
	if (visited[node])
		return false;
	onpath[node] = visited[node] = true;
	for (int neigh : graph[node])
		if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
			return true;
	return onpath[node] = false;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
	vector<bool> onpath(numTasks, false), visited(numTasks, false);
	for (int i = 0; i < numTasks; i++)
		if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
			return false;
	return true;
}

int main()
{
	int numTasks = 4;

	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]

	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	if (canFinish(numTasks, prerequisites)) {
		cout << "Possible to finish all tasks";
	}
	else {
		cout << "Impossible to finish all tasks";
	}

	return 0;
}

// Minimum Weignt spanning tree
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V];int res=0; 
    	fill(key,key+V,INT_MAX);
    	bool mSet[V]; key[0]=0; 
        for (int count = 0; count < V ; count++) 
    	{ 
    		int u = -1; 
    
    		for(int i=0;i<V;i++)
        		if(!mSet[i]&&(u==-1||key[i]<key[u]))
        		        u=i;
        		mSet[u] = true; 
        		res+=key[u];
    
    		
    // 		for (int v = 0; v < V; v++) 
    // 			if (graph[u][v]!=0 && mSet[v] == false) 
    // 				key[v] = min(key[v],graph[u][v]); 
            for(auto it : adj[u]){
                if(mSet[it[0]] == false)
                    key[it[0]] = min(key[it[0]], it[1]);
            }
    	} 
        return res;
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       int graph[V][V] = {0};
       for(int k = 0; k < V; k++){
           for(auto it:adj[k]){
               graph[k][it[0]] = it[1];
              
           }
       }
            //   for(int i = 0; i < V; i++){
            //     for(int j= 0; j < V; j++){
            //         cout<<graph[i][j]<<' ';
            //     }
            //     cout<<endl;
            //   }

        int key[V];
        int res=0; 
    	fill(key,key+V,INT_MAX);
    	bool mSet[V] = {false};
    	key[0]=0;
        
    	for (int count = 0; count < V ; count++) 
    	{ 
    		
            int u = -1; 
    		for(int i=0;i<V;i++)
    		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
    		        u=i;
    		mSet[u] = true; 
    		res+=key[u];
    
    		
    		for (int v = 0; v < V; v++) 
    			if (graph[u][v]!=0 && mSet[v] == false) 
    				key[v] = min(key[v],graph[u][v]); 
    	} 
        return res;
    }
};

/*******************************************************************/
//Kosaraju's Algorithm
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int u, vector<int>adj[], bool *vis, stack<int> &s){
        vis[u] = true;
        
        for(int v: adj[u]){
            if(!vis[v]){
                dfs(v, adj, vis, s);
            }
        }
        s.push(u);
    }
    int kosaraju(int V, vector<int> adj[])
    {
       
        // Your code here
        stack<int> s;
        int cnt = 0;
        
        bool vis[V];    memset(vis, false, sizeof(vis));
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, s);
            }
        }
        
        vector<int> transpose[5000];
        
        for(int i=0; i<V; i++){
            for(int v: adj[i]){
                transpose[v].push_back(i);
            }
        }
        
        stack<int> st;
        cnt = 0;
        memset(vis, false, V);
        
        while(!s.empty()){
            if(!vis[s.top()]){
                dfs(s.top(), transpose, vis, st);
                cnt++;
            }
            s.pop();
        }    
        return cnt;
    } //code here
};
// Rotten oranges 
class Solution 
{
    public:
    bool isvalid(int i, int j, vector<vector<int>> arr)
    {
        return (i >= 0 && j >= 0 && i < arr.size() && j < arr[0].size());
    }
    bool isdelim(pair<int,int> temp)
    {
        return (temp.first == -1 && temp.second == -1);
    }
     
    // Function to check whether there is still a fresh
    // orange remaining
    bool checkall(vector<vector<int>> arr)
    {
        for (int i=0; i<arr.size(); i++)
           for (int j=0; j<arr[i].size(); j++)
              if (arr[i][j] == 1)
                 return true;
        return false;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& arr) {
        int ans = 0;
        // Code here
        pair<int,int> temp;
        queue<pair<int,int>> q;
        for(int i = 0; i<arr.size(); i++){
            for(int j = 0; j<arr[i].size(); j++){
                if(arr[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        while (!q.empty())
        {
            // This flag is used to determine whether even a single fresh
            // orange gets rotten due to rotten oranges in current time
            // frame so we can increase the count of the required time.
            bool flag = false;
        
            // Process all the rotten oranges in current time frame.
            while (!(q.front().first == -1 && q.front().second == -1))
            {
                temp = q.front();
     
                // Check right adjacent cell that if it can be rotten
                if (isvalid(temp.first+1, temp.second, arr) && arr[temp.first+1][temp.second] == 1)
                {
                    // if this is the first orange to get rotten, increase
                    // count and set the flag.
                    if (!flag) ans++, flag = true;
     
                    // Make the orange rotten
                    arr[temp.first+1][temp.second] = 2;
     
                    // push the adjacent orange to Queue
                    temp.first++;
                    q.push(temp);
     
                    temp.first--;// Move back to current cell
                }
     
                // Check left adjacent cell that if it can be rotten
                if (isvalid(temp.first-1, temp.second, arr) && arr[temp.first-1][temp.second] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.first-1][temp.second] = 2;
                    temp.first--;
                    q.push(temp); // push this cell to Queue
                    temp.first++;
                }
     
                // Check top adjacent cell that if it can be rotten
                if (isvalid(temp.first, temp.second+1, arr) && arr[temp.first][temp.second+1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.first][temp.second+1] = 2;
                    temp.second++;
                    q.push(temp); // Push this cell to Queue
                    temp.second--;
                }
     
                // Check bottom adjacent cell if it can be rotten
                if (isvalid(temp.first, temp.second-1, arr) && arr[temp.first][temp.second-1] == 1) {
                    if (!flag) ans++, flag = true;
                    arr[temp.first][temp.second-1] = 2;
                    temp.second--;
                    q.push(temp); // push this cell to Queue
                }
     
                q.pop();
            }
     
            // Pop the delimiter
            q.pop();
     
            // If oranges were rotten in current frame than separate the
            // rotten oranges using delimiter for the next frame for processing.
            if (!q.empty()) {
                temp.first = -1;
                temp.second = -1;
                q.push(temp);
            }
            // If Queue was empty than no rotten oranges left to process so exit
        }
        return (checkall(arr))? -1: ans;

    }
};
// Accepted Code GFG
class Solution 
{
    public:
    void rot(vector<vector<int>>&m, int r, int c, int x, int y, queue<pair<int, int>>&q, vector<vector<int>>&visited) {
        if(x+1<r && (m[x+1][y] == 1) && !visited[x+1][y]) {
            m[x+1][y] = 2;
            q.push({x+1, y});
        }
        if(x-1>=0 && m[x-1][y] == 1 && !visited[x-1][y]) {
            m[x-1][y] = 2;
            q.push({x-1, y});
        }
        if(y-1>=0 && m[x][y-1] == 1 && !visited[x][y-1]) {
            m[x][y-1] = 2;
            q.push({x, y-1});
        }
        if(y+1<c && m[x][y+1] == 1 && !visited[x][y+1]) {
            m[x][y+1] = 2;
            q.push({x, y+1});
        }
    }
    
    int rotOranges(vector<vector<int> > &m, int r, int c) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(r, vector<int>(c, 0));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(m[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push({-1, -1});
        int ans = 0;
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if(x < 0) {
                ans = max(ans, abs(x));
                if(!q.empty())
                    q.push({x-1, y-1});
                continue;
            }
            visited[x][y] = 1;
            rot(m, r, c, x, y, q, visited);
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                // cout << m[i][j] << " ";
                if(m[i][j] == 1)
                    return -1;
            }
            // cout << "\n";
        }
        return ans-1;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& arr) {
    
        return rotOranges(arr,arr.size(),arr[0].size());

    }
};
/****************************************************************************/
// Bipartite Graph - https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
class Solution {
    public:
        bool bfs(int s, vector<int> &color, vector<int> adj[]){
            color[s] = 0;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(color[v] == -1){
                        color[v] = !color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u])
                        return false;
                }
            }
            return true;
        }
    	bool isBipartite(int V, vector<int>adj[]){
    	    // Code here
    	    vector<int> color(V, -1);
    	    for(int i = 0; i<V; i++){
    	        if(color[i] == -1){
    	            if(!bfs(i, color, adj))
    	                return false;
    	        }
    	    }
    	    return true;
    	}
};
/*************************************************************************/


