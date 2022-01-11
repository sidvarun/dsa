// TLE

class Solution {
public:
    int res;
    void dfs(vector<vector<int>>& heights, int i, int j, int currDiff, int maxDiff, vector<vector<int>>& directions){
        if(i == heights.size() - 1 && j == heights[0].size() - 1){
            res = min(res, maxDiff);
            return;
        }
        for(auto direc : directions){
            int x = i + direc[0];
            int y = j + direc[1];
            
            if(x >= 0 && y >= 0 && x < heights.size() && y < heights[0].size() && heights[x][y] != 0){
                currDiff = abs(heights[i][j] - heights[x][y]);
                maxDiff = max(maxDiff, currDiff);
                int temp = heights[i][j];
                heights[i][j] = 0;
                dfs(heights, x, y, currDiff, maxDiff, directions);
                heights[i][j] = temp;
                currDiff = 0;
                maxDiff = 0;
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        res = INT_MAX;
        dfs(heights, 0, 0, 0, 0, directions);
        return res;
    }
};
/********************************************************/

