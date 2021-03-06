// 22. Minimum Cost Path  - https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/?track=mts-dynamic-programming&batchId=341
class Solution 
{
    public:
	struct cell
	{
		int x;
		int y;
		int distance;
		bool operator<(cell other)const{
			if(distance == other.distance){
				if(x != other.x)
					return x < other.x;
				return y < other.y;
			}
			return distance < other.distance;
		}
	};
	
    //these list store 4 possible moves from current cell.
	vector<int>dx = {-1,1,0,0};
	vector<int>dy = {0,0,1,-1};
	
	//Function to check if cell indexes are within bounds.
	bool isValid(int x, int y, int n, int m){
		return (x >=0 and x < n and y >=0 and y < m);
	}
	
	//Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
    	int n = grid.size();
    	int m = grid[0].size();
    	
    	//dp list to store minimum cost to reach each cell.
    	vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
    	
    	//using a set to store cell indexes and minimum cost to reach that cell.
    	set<cell>st;
    	st.insert({0,0,0});
    	dp[0][0] = grid[0][0];
    	
    	while(!st.empty())
    	{
    	    //storing first element of set and erasing it from set.
    		auto cur = *st.begin();
    		st.erase(st.begin());
    		
    		//iterating over 4 possible neighbours of current cell.
    		for(int i = 0; i < 4; i++)
    		{
    			int x = cur.x + dx[i];
    			int y = cur.y + dy[i];
    			
    			//if cell indexes are within bounds and dp value at 
    			//neighbouring cell+current cell value is less than at 
    			//current cell, we update dp value at current cell and
    			//insert cell index with dp value in set.
    			if(isValid(x,y,n,m) and dp[x][y]>dp[cur.x][cur.y]+grid[x][y])
    			{
    				if(dp[x][y] != INT_MAX)
    					st.erase(st.find({x, y, dp[x][y]}));
    				dp[x][y] = dp[cur.x][cur.y] + grid[x][y];
    				st.insert({x, y, dp[x][y]});
    			}
    		}
    	}
    	//returning dp value at bottom right corner cell.
    	return dp[n-1][m-1];
    }
};
/******************************************************************************************/
// 27. Form a palindrome - https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1/?track=mts-dynamic-programming&batchId=341#
/*
    The minimum number of insertions in the string str[l???..h] can be given as:
    minInsertions(str[l+1???..h-1]) if str[l] is equal to str[h]
    min(minInsertions(str[l???..h-1]), minInsertions(str[l+1???..h])) + 1 otherwise
*/
class Solution{   
public:
    int dp[501][501];
    int minInsertions(string s, int l, int h){
        if(l >= h)
            return 0;
        if(dp[l][h] != -1)
            return dp[l][h];
        if(s[l] == s[h])
            dp[l][h] = minInsertions(s, l + 1, h - 1);
        else
            dp[l][h] = 1 + min(minInsertions(s, l + 1, h), minInsertions(s, l, h - 1));
        return dp[l][h];
    }
    int findMinInsertions(string s){
        // code here 
        memset(dp, -1, sizeof(dp));
        return minInsertions(s, 0, s.length() - 1);
    }
};
/*******************************************************************************************/
// 279. Perfect Squares - https://leetcode.com/problems/perfect-squares/
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                cntPerfectSquares[i] = 
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            }
        }
        
        return cntPerfectSquares.back();
    }
};
/******************************************************************************************/
// 1691. Maximum Height by Stacking Cuboids - https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
class Solution {
public:
    // static bool cmp(vector<int> a, vector<int> b){
    //     if(a[0] != b[0])
    //         return a[0] < b[0];
    //     if(a[1] != b[1])
    //         return a[1] < b[1];
    //     return a[2] < b[2];
    // }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &v : cuboids)
            sort(v.begin(), v.end());
        sort(cuboids.begin(), cuboids.end());
        int res = INT_MIN;
        int n = cuboids.size();
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++){
            int maxm = 0;
            // dp[i] = cuboids[i][2];
            for(int j = 0; j<i; j++){
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    maxm = max(maxm, dp[j]);
                    // dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
            }
            dp[i] = maxm + cuboids[i][2];
            res = max(res, dp[i]);
        }
        return res;
    }
};