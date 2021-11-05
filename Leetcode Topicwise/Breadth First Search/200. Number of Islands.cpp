https://leetcode.com/problems/number-of-islands/

/*
Approach #2: BFS [Accepted]
Algorithm

Linear scan the 2d grid map, if a node contains a '1', then it is a root node that triggers a Breadth First Search. 
Put it into a queue and set its value as '0' to mark as visited node. Iteratively search the neighbors of enqueued
nodes until the queue becomes empty.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    res++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int> u = q.front();
                        q.pop();
                        for(auto dir : directions){
                            int x = u.first + dir[0];
                            int y = u.second + dir[1];
                            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1'){
                                grid[x][y] = '0';
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};