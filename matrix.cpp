// https://practice.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1
class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > mat)
    {   
        // code here
        vector<int> res;
        for(int i = 0; i < mat.size(); i++)
    	{
    		if(i % 2 == 0)
    		{
    			for(int j = 0; j < mat[i].size(); j++)
    				res.push_back(mat[i][j]);
    		}
    		else
    		{
    			for(int j = mat[i].size() - 1; j >= 0; j--)
    			    res.push_back(mat[i][j]);
    		}
    	}
    	return res;
    }
};
/******************************************************************************************/
// Boundary Elements of Matrix - https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1
class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&m){
        // Code here
        vector<int> res;
        int l = m.size();
        int b = m[0].size();
        for(int i = 0; i<l; i++){
            for(int j = 0; j<b; j++){
                if(i+1 >= l || i-1 < 0 || j+1 >= b || j-1 <0)
                    res.push_back(m[i][j]);
            }
        }
        return res;
    }
};

/**********************************************************************************************/

// https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1#
class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& m, int n)
    { 
        // code here 
        int temp;

        for(int i = 0; i < n; i++){
    		for(int j = 0; j <= i; j++){
    		    if(i != j){
    		        temp = m[i][j];
    		        m[i][j] = m[j][i];
    		        m[j][i] = temp;
    		    }
    		}
    	}
    }
};
/*********************************************************************************************/
// Rotate Matirix 90 degreees clockwise - https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1#

void transpose(vector<vector<int> >& m, int n)
{ 
        // code here 
    int temp;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j <= i; j++){
    		   if(i != j){
    		      temp = m[i][j];
    		      m[i][j] = m[j][i];
    		      m[j][i] = temp;
    		   }
    	}
    }
}


void rotate(vector<vector<int> >& m)
{
    // Your code goes here
    transpose(m, m.size());
    for(int j = 0; j<m.size(); j++){
        for(int i = 0; i<m.size()/2; i++)
            swap(m[i][j], m[m.size() - i - 1][j]);
    }
}
/************************************************************************************************/

// Spirally traversing a matrix - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int R, int C) 
    {
        // code here 
        vector<int> res;
        int t, b, r, l;
        t = 0;
        b = R-1;
        r = C-1;
        l = 0;
        int d = 0;
        while(l<=r && t<=b){
            if(d == 0){
                for(int j = l; j<=r; j++)
                    res.push_back(m[t][j]);
                t++;
            }
            else if(d == 1){
                for(int i = t; i<=b; i++)
                    res.push_back(m[i][r]);
                r--;
            }
            else if(d == 2){
                for(int j = r; j>=l; j--)
                    res.push_back(m[b][j]);
                b--;
            }
            else if(d == 3){
                for(int i = b; i>=t; i--)
                    res.push_back(m[i][l]);
                l++;
            }
            d = (d + 1) % 4; 
        }
        return res;
    }
};

/*********************************************************************************************************************/

// Search in a row-column sorted Matrix - https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > mt, int n, int m, int x) 
    {
        // code here 
        int i = 0;
        int j = m - 1;
        while(i<n && j>=0){
            if(mt[i][j] == x)
                return true;
            else if(mt[i][j] > x)
                j--;
            else
                i++;
        }
        return false;
    }
};
/********************************************************************************************************************/

// Median in a row-wise sorted Matrix - https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/0/?category

class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
        // code here         
        int min = mat[0][0], max = mat[0][c-1];
    	for (int i=1; i<r; i++)
    	{
    		if (mat[i][0] < min)
    			min = mat[i][0];
    
    		if (mat[i][c-1] > max)
    			max = mat[i][c-1];
    	}
    
    	int medPos = (r * c + 1) / 2;
    	while (min < max)
    	{
    		int mid = (min + max) / 2;
    		int midPos = 0;
    
    		for (int i = 0; i < r; ++i)
    			midPos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    		if (midPos < medPos)
    			min = mid + 1;
    		else
    			max = mid;
    	}
    	return min;
    }
};
/**********************************************************************************************************************/
// Boolean Matrix - https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1/?track=DSASP-Matrix&batchId=154#

class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &m)
    {
        // code here 
        bool row[m.size()] = {false};
        bool col[m[0].size()] = {false};
        for(int i = 0; i<m.size(); i++)
            for(int j = 0; j<m[0].size(); j++)
                if(m[i][j] == 1){
                    row[i] = true;
                    col[j] = true;
                }
        for(int i = 0; i<m.size(); i++)
            for(int j = 0; j<m[0].size(); j++)
                if(row[i] || col[j])
                    m[i][j] = 1;
    }
};
/*************************************************************************************************************************/
// Kth element in Matrix - https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#
int kthSmallest(int m[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
  for(int j = 0; j<n; j++)
    pq.push({m[0][j],{0,j}});
  while(k>1){
      pair<int,pair<int, int>> temp = pq.top();
      pq.pop();
      int data = temp.first;
      int x = temp.second.first;
      int y = temp.second.second;
      if(x<n-1)
        pq.push({m[x+1][y], {x+1, y}});
      k--;
  }
  return pq.top().first;
}

/************************************************************************************************************************/

// Sorted matrix - https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1
class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> m) {
        // code here
         vector<vector<int>> res;
         priority_queue<int, vector<int>, greater<int> > pq;
         for(int i = 0; i<m.size(); i++){
             for(int j = 0; j<m[0].size(); j++){
                 pq.push(m[i][j]);
             }
         }
        for(int i = 0; i<m.size(); i++){
            vector<int> t;
            for(int j = 0; j<m[0].size(); j++){
                t.push_back(pq.top());
                pq.pop();
            }
            res.push_back(t);
        }
        return res;
    }
};
/*****************************************************************************************************************/
// Row with max 1s - https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int m, int n) {
	    // code here
	    int pos, res, subres, cmin;
	    cmin = INT_MAX;
	    pos = INT_MAX;
	    for(int i = 0; i<m; i++){
	        for(int j = 0; j<n; j++){
	            if(arr[i][j] == 1){
	                subres = i;
	                pos = j;
	                break;
	            }
	        }
	        if(pos<cmin){
	            res = subres;
	            cmin = pos;
	        }
	    }
	    if(cmin != INT_MAX)
	        return res;
	    return -1;
	    
	}

};
/******************************************************************************************************/
// Max rectangle - https://practice.geeksforgeeks.org/problems/max-rectangle/1

class Solution{
  public:
    int getMaxArea(int arr[], int n){
        // Your code here
        stack<int> s;
        int res,curr;
        res = INT_MIN;
        for(int i = 0; i<n; i++){
            while(s.empty() == false && arr[s.top()]>=arr[i]){
                int tp = s.top();
                s.pop();
                curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                res = max(res,curr);
            }
            s.push(i);
        }
        while(s.empty() == false){
            int tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res,curr);
        }
        return res;
    }
    int maxArea(int M[MAX][MAX], int m, int n) {
        // Your code here
        int arr[n];
        // int p = 0;
        for(int j = 0; j<n; j++)
            arr[j] = M[0][j];
        int res = getMaxArea(arr, n);
        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                if(M[i][j] == 0)
                 arr[j] = 0;
                else
                 arr[j] += M[i][j];
            }
            res = max(res, getMaxArea(arr, n));
        }
        return res;
    }
};
/*****************************************************************************************************/