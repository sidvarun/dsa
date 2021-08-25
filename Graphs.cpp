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
                if(DFSRec(adj,u,visited,s)==true){
                    return true;
                }
            }
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
// geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
// A DFS based approach to find if there is a cycle
// in a directed graph. This approach strictly follows
// the algorithm given in CLRS book.
#include <bits/stdc++.h>
using namespace std;

enum Color {WHITE, GRAY, BLACK};

// Graph class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices
	list<int>* adj; // adjacency lists

	// DFS traversal of the vertices reachable from v
	bool DFSUtil(int v, int color[]);
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	bool isCyclic();
};

// Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// Utility function to add an edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[])
{
	// GRAY : This vertex is being processed (DFS
	//		 for this vertex has started, but not
	//		 ended (or this vertex is in function
	//		 call stack)
	color[u] = GRAY;

	// Iterate through all adjacent vertices
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // An adjacent of u

		// If there is
		if (color[v] == GRAY)
		return true;

		// If v is not processed and there is a back
		// edge in subtree rooted with v
		if (color[v] == WHITE && DFSUtil(v, color))
		return true;
	}

	// Mark this vertex as processed
	color[u] = BLACK;

	return false;
}

// Returns true if there is a cycle in graph
bool Graph::isCyclic()
{
	// Initialize color of all vertices as WHITE
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = WHITE;

	// Do a DFS traversal beginning with all
	// vertices
	for (int i = 0; i < V; i++)
		if (color[i] == WHITE)
		if (DFSUtil(i, color) == true)
			return true;

	return false;
}

// Driver code to test above
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";

	return 0;
}

/*********************************************************************************/
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
    // C
    
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
	void dfs(int u, vector<int>adj[], vector<bool> &vis, stack<int> &s){
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
        
        vector<bool> vis(V, false);
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
        
        stack<int> st; // This stack has no use, its places just that we dont have to write a seperate DFS
        cnt = 0;
        for(int i = 0; i<V; i++)
            vis[i] = false;
        
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
// Implementing Dijkstra Algorithm - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>> > pq;
        vector<int> dist(V, INT_MAX);
        dist[s] = 0;
        pq.push({0, s});
        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto v : adj[u]){
                if( d + v[1] < dist[v[0]]){
                    dist[v[0]] = d + v[1];
                    pq.push({dist[v[0]], v[0]});
                }
            }
        }
        return dist;
    }
};
/***************************************************************************/
// Minimum Spanning Tree - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;
        // mst[0] = true;
        int num = 1;
        int u = 0;
        while(num <= V){
            mst[u] = true;
            for(auto v : adj[u]){
                if(mst[v[0]] == false){
                    if(v[1] < key[v[0]]){
                        key[v[0]] = v[1];
                        parent[v[0]] = u;
                    }
                }
            }
            int min = INT_MAX;
            for(int i = 0; i<key.size(); i++){
                if(mst[i] == false && key[i]<min){
                    min = key[i];
                    u = i;
                }
            }
            num++;
        }
        int res = 0;
        for(int i = 0; i<key.size(); i++)
            res+=key[i];
        return res;
    }
};
/***************************************************************************************/
// Distance from the Source (Bellman-Ford Algorithm)  - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V, 100000000);
        dist[S] = 0;
        for(int i = 0; i<V-1; i++){
            bool notUpdate = true;
            for(auto edge : adj){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                     notUpdate = false;
                }
            }
            if(notUpdate)
                break;
        }
        return dist;
    }
};
/******************************************************************************************/
// Negative weight cycle - https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>adj){
	    // Code here
	    vector<int> dist(V, 100000000);
        dist[0] = 0;
        for(int i = 0; i<V-1; i++){
            bool notUpdate = true;
            for(auto edge : adj){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                     notUpdate = false;
                }
            }
            if(notUpdate)
                break;
        }
        for(auto edge : adj){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] + w < dist[v]){
                    return 1;
                }
        }
        return 0;
        
	}
};
/************************************************************************************************/
// Alien Dictionary - https://practice.geeksforgeeks.org/problems/alien-dictionary/1#

class Solution{
    public:
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
    string findOrder(string dict[], int n, int k) {
        //code here
        set<int> adj[k];
        for(int i = 0; i<n-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int x = 0;
            int y = 0;
            while(x<s1.length() && y<s2.length()){
                if(s1[x] != s2[y]){
                    adj[s1[x] - 'a'].insert(s2[y] - 'a');
                    break;
                }
                x++;
                y++;
            }
        }
        vector<int> adj1[k];
        for(int i = 0; i<k; i++){
            for(auto j : adj[i])
                adj1[i].push_back(j);
        }
        vector<int> res = topoSort(k, adj1);
        string str = "";
        for(auto c : res){
            str +=char(c + 'a');
            // cout<<char(c + 'a')<<" ";
        }
        return str;
    }
};
/*****************************************************************************************/

int bfs(int s, vector<pair<int, int>> adj[]){
        bool visited[31];
        int dist[31];
        queue<int> q;
        
        fill(dist, dist+31, -1);
        dist[s] = 0;
        q.push(s);
        visited[s] = true;
        int throws = 0;
        
        while(!q.empty()){
            throws++;
            int u = q.front();
            q.pop();
    
            for(auto v : adj[u]){
                if(visited[v.first]==false){
                    dist[v.first] = dist[u] + v.second;
                    visited[v.first] = true;
                    q.push(v.first);
                }
            }
        }
        /*for(int i=1; i<31; i++)
            cout<<dist[i]<<" ";*/
        return dist[30];
    }
    int minThrow(int N, int arr[]){
        // code here
        vector<pair<int, int>> adj[31];
        for(int i = 0; i<2*N - 1;){
            adj[arr[i]].push_back({arr[i+1], 0});
            i=i+2;
        }
        for(int i = 1; i<30; i++){
            if(adj[i].empty()){
                int c = 0;
                int j = i+1;
                while(j<=30 && c<=6){
                    adj[i].push_back({j, 1});
                    j++;
                    c++;
                }
            }
        }
        // adj[30].push_back({1, 1});

        return bfs(1, adj);
    }

    //////////////////////////////////////////////////////////////////
// Snake and Ladder Problem - https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1#
class Solution{
    public:
        int bfsAdjList(int s, vector<int> adj[]){
        bool visited[31];
        int dist[31];
        queue<int> q;
        
        fill(dist, dist+31, -1);
        dist[s] = 0;
        q.push(s);
        visited[s] = true;
        int throws = 0;
        
        while(!q.empty()){
            throws++;
            int v = q.front();
            q.pop();
    
            for(int u : adj[v]){
                if(visited[u]==false){
                    dist[u] = dist[v]+1;
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
  
        return dist[30];
    }
    
    int minThrow(int n, int arr[]){
        /*Hash map for start and end of ladder/snake*/
        unordered_map<int, int> um;
        for(int i=0; i<n*2; i+=2)
            um[arr[i]] = arr[i+1];
        
        /*Make adj list for graph*/
        vector<int> adj[31];
        for(int i=1; i<30; i++){
            for(int j=0; j<6; j++){
                if(i+j+1 <31){
                    if(um.find(i+j+1) != um.end())
                        adj[i].push_back(um[i+j+1]);
                    else
                        adj[i].push_back(i+j+1);
                }
            }
        }
        return bfsAdjList(1, adj);
    }
};
/******************************************************************************************/
// Number of Triangles in Directed and Undirected Graphs - https://www.geeksforgeeks.org/number-of-triangles-in-directed-and-undirected-graphs/

// C++ program to count triangles
// in a graph. The program is for
// adjacency matrix representation
// of the graph.
#include<bits/stdc++.h>

// Number of vertices in the graph
#define V 4

using namespace std;

// function to calculate the
// number of triangles in a
// simple directed/undirected
// graph. isDirected is true if
// the graph is directed, its
// false otherwise
int countTriangle(int graph[V][V],
				bool isDirected)
{
	// Initialize result
	int count_Triangle = 0;

	// Consider every possible
	// triplet of edges in graph
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
			// Check the triplet if
			// it satisfies the condition
			if (graph[i][j] && graph[j][k]
							&& graph[k][i])
				count_Triangle++;
			}
		}
	}

	// If graph is directed ,
	// division is done by 3,
	// else division by 6 is done
	isDirected? count_Triangle /= 3 :
				count_Triangle /= 6;

	return count_Triangle;
}

//driver function to check the program
int main()
{
	// Create adjacency matrix
	// of an undirected graph
	int graph[][V] = { {0, 1, 1, 0},
					{1, 0, 1, 1},
					{1, 1, 0, 1},
					{0, 1, 1, 0}
					};

	// Create adjacency matrix
	// of a directed graph
	int digraph[][V] = { {0, 0, 1, 0},
						{1, 0, 0, 1},
						{0, 1, 0, 0},
						{0, 0, 1, 0}
					};

	cout << "The Number of triangles in undirected graph : "
		<< countTriangle(graph, false);
	cout << "\n\nThe Number of triangles in directed graph : "
		<< countTriangle(digraph, true);

	return 0;
}
/***********************************************************************************************************************************/
