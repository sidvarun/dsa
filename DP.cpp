// Nth Fibonacci Number Using memoization
class Solution {
  public:
  long long int Fibonacci(long long int n, vector<long long int> &memo){
        // code here
        int res = 0;
        if(memo[n] == -1){
            if(n==0 || n==1)
                res = n;
            else{
                res = Fibonacci(n-1, memo)%1000000007 + Fibonacci(n-2, memo)%1000000007;
            }
            memo[n] = res;
        }
        return memo[n];
    }
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> memo(n+1, -1);
        return Fibonacci(n,memo)%1000000007;
    }
};
/******************************************************************************************/
// Coin channge problem
class Solution
{
  public:
    long long int count( int s[], int m, int n)
    {
       long long int dp[n+1][m+1];
        for(int i = 0; i < m+1; i++)
            dp[0][i] = 1;
        for(int j = 1; j < n+1; j++)
            dp[j][0] = 0;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s[j-1] <= i)
                    dp[i][j] = dp[i - s[j-1]][j] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];
       
    }
};
/*****************************************************************************************/

// 0-1 Knapsack 
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[W+1][n+1];
       for(int i = 0; i< W + 1; i++)
           dp[i][0] = 0;
       for(int j = 0; j< n+1; j++)
           dp[0][j] = 0;
       for(int i = 1; i< W + 1; i++){
          for(int j = 1; j< n+1; j++){
              if(wt[j-1] <= i)
                dp[i][j] = max(val[j-1] + dp[i - wt[j-1]][j-1], dp[i][j-1]);
              else
                dp[i][j] = dp[i][j-1];
          }
       }
        return dp[W][n];
    }
};
/**********************************************************************************************/

// nCr

class Solution{
public:
    int nCr(int n, int r){
        // code here
        long long int dp[r+1][n+1];
        for(int i = 0; i<r+1; i++){
            for(int j = 0; j<n+1; j++){
                if(i>j)
                    dp[i][j] = 0;
                else if(i == 0 || i == j)
                    dp[i][j] = 1;
            }
        }
        for(int i = 0; i<r+1; i++){
            for(int j = 0; j<n+1; j++){
                if( i < j && i!=0 && i!=j)
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j-1])%(1000000007);
            }
        }
        return dp[r][n];
    }
};
/********************************************************************************************************/
// Edit Distance
class Solution {
  public:
    int editDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        int dp[m+1][n+1];
        for(int i=0; i<m+1; i++)
            dp[i][0] = i;
        for(int j=0; j<n+1; j++)
            dp[0][j] = j;
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[m][n];
    }
};
/**************************************************************************************************************/
// Friends Pairing Problem
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n + 1];
        for (int i = 0; i <= n; i++) {
            if (i <= 2)
                dp[i] = i;
            else
                dp[i] = (dp[i - 1]%1000000007 + (i - 1)%1000000007 * dp[i - 2]%1000000007)%1000000007;
        }
     
        return dp[n];
    }
};    
/*****************************************************************************************************************/
// Partition Equal Subset Sum
class Solution{
public:
    int subsetSum(int n, int arr[], int sum){
        int dp[sum+1][n+1];
        for(int j = 0; j<n+1; j++)
            dp[0][j] = 1;
        for(int i = 1; i<sum+1; i++)
            dp[i][0] = 0;
        for(int i = 1; i<sum+1; i++){
            for(int j = 1; j<n+1; j++){
                dp[i][j] = dp[i][j-1];
                if(i>=arr[j-1])
                    dp[i][j] = dp[i-arr[j-1]][j-1] || dp[i][j-1];
            }
        }
        return dp[sum][n];
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += arr[i];
        if(sum % 2 != 0)
            return 0;
        else 
            return subsetSum(n, arr, sum/2);
    }
};
/******************************************************************************************************************/
//Maximize The Cut Segments
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int dp[n+1] = {-1};
        dp[0] = 0;
        for(int i = 1; i<n+1; i++){
            dp[i] = -1;
            // dp[i] = 1 + max(dp[i - x], max(dp[i - y], dp[i - z]));
            if(i>=x)
             dp[i] = max(dp[i],dp[i-x]);
            if(i>=y)
             dp[i] = max(dp[i],dp[i-y]);
            if(i>=z)
             dp[i] = max(dp[i],dp[i-z]);
            if(dp[i] != -1)
                dp[i]++;
        }
        return max(dp[n], 0);
    }
};
/*************************************************************************************************************************/
// Painting the Fence
class Solution{
    public:
    long long countWays(int n, int k){
        // code heren
        long long int dp[n+1];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        for(int i = 3; i<n+1; i++)
            dp[i] = ((k-1)%1000000007 * (dp[i-1]%1000000007 + dp[i-2]%1000000007))%1000000007;
        return dp[n];
    }
};
/**************************************************************************************************************************/
// Reach a given score(Same as coin change problem)

long long int count(long long int n)
{
	    int s[] = {3, 5, 10};
	    int m = 3;
	    long long int dp[n+1][m+1];
        for(int i = 0; i < m+1; i++)
            dp[0][i] = 1;
        for(int j = 1; j < n+1; j++)
            dp[j][0] = 0;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s[j-1] <= i)
                    dp[i][j] = dp[i - s[j-1]][j] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];
}
/***********************************************************************/
// Stickler Thief - https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n+1] = {0};
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2; i<=n; i++)
            dp[i] = max(arr[i-1] + dp[i-2], dp[i-1]);
        return dp[n];
        
    }
};

/***************************************************************************/

// Matrix Chain Multiplication - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:
    int solve(int arr[], vector<vector<int>> &dp, int i, int j){
        if(i >= j)
            return 0;
        int res = INT_MAX;
        if(dp[i][j] != -1)
            res = dp[i][j];
        else{
            for(int k = i; k<j; k++){
                int tempRes = solve(arr, dp, i, k) + solve(arr, dp, k+1, j) + arr[i-1] * arr[k] * arr[j];
                res = min(res, tempRes);
                dp[i][j] = res;
            }
        }
        return res;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(arr, dp, 1, n-1);
    }
};
/***************************************************************************/

// Palindromic patitioning - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

class Solution{
public:
    bool isPalindrome(string str, int i, int j){
        int l = i;
        int r = j;
        while(l<r){
            if(str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    int solve(string &str, vector<vector<int>> &dp, int i, int j){
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(isPalindrome(str, i, j)){
            dp[i][j] = 0;
            return dp[i][j];
        }
        int res = INT_MAX;
        int tempRes;
        for(int k = i; k<=j-1; k++){
            tempRes = solve(str, dp, i, k) + solve(str, dp, k+1, j) + 1;
            res = min(res, tempRes);
        }
        dp[i][j] = res;
        return res;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(str, dp, 0, n-1);
    }
};
/*****************************************************************************/
public:
    int solve(string &s, int i, int j, int val, vector<vector<vector<int>>> &dp){
        if(dp[i][j][val] != -1)
            return dp[i][j][val];
        if(i>j){
            dp[i][j][val] = 0;
            return dp[i][j][val];
        }
        if(i == j){
            if(val)
                dp[i][j][val] = s[i] == 'T';
            else
                dp[i][j][val] = s[i] == 'F';
            return dp[i][j][val];
        }
        int res = 0;
        for(int k = i+1; k<j; k += 2){
            if(dp[i][k-1][1] == -1)
                solve(s, i, k-1, 1, dp);
            if(dp[i][k-1][0] == -1)
                solve(s, i, k-1, 0, dp);
            if(dp[k+1][j][1] == -1)
                solve(s, k+1, j, 1, dp);
            if(dp[k+1][j][0] == -1)
                solve(s, k+1, j, 0, dp);
            int lt = dp[i][k-1][1];
            int lf = dp[i][k-1][0];
            int rt = dp[k+1][j][1];
            int rf = dp[k+1][j][0];
            // int lt = solve(s, i, k-1, 1, dp);
            // int lf = solve(s, i, k-1, 0, dp);
            // int rt = solve(s, k+1, j, 1, dp);
            // int rf = solve(s, k+1, j, 0, dp);
            if(s[k] == '|'){
                if(val)
                    res += lt * rt + lf * rt + lt * rf;
                else
                    res += lf * rf;
            }
                // res += solve(s, i, k-1, true, dp) * solve(s, k+1, j, true, dp) + solve(s, i, k-1, false, dp) * solve(s, k+1, j, true, dp) + solve(s, i, k-1, true, dp) *  solve(s, k+1, j, false, dp);
            else if(s[k] == '&'){
                if(val)
                    res += lt * rt;
                else
                    res += lf * rf + lf * rt + lt * rf;
            }

                // res += solve(s, i, k-1, true, dp) * solve(s, k+1, j, true, dp);
            else if(s[k] == '^'){
                if(val)
                    res += lt * rf + lf * rt;
                else
                    res += lt * rt + lf * rf;
            }
                // res += solve(s, i, k-1, true, dp) * solve(s, k+1, j, false, dp) + solve(s, i, k-1, false, dp) * solve(s, k+1, j, true, dp);
        
            dp[i][j][val] = res%1003;

        }
        // dp[i][j][val] = res%1003;
        return dp[i][j][val]%1003;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int> >(n,vector <int>(2,-1)));
        return solve(s, 0, n-1, 1, dp)%1003;
    }

    // Boolean Parenthesization  - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

    class Solution{
public:
    int dp[210][210][3];
    int rec(string &s,int i,int j,bool istrue){
        if(i>j){
            return dp[i][j][istrue] = 0;
        }else if(i==j){
            return dp[i][j][istrue] = (istrue)?((s[i]=='T')?1:0):((s[i]=='F')?1:0);
        }
        else if(dp[i][j][istrue]!=-1){
            return dp[i][j][istrue];
        }
        int ans = 0;
        for(int k=i+1;k<=j-1;k+=2){
            
            int lT;
            if(dp[i][k-1][1]!=-1)  
                lT = dp[i][k-1][1];
            else                   
                lT = rec(s,i,k-1,true) ;
            
            int lF;
            if(dp[i][k-1][0]!=-1)  
                lF = dp[i][k-1][0];
            else
                lF = rec(s,i,k-1,false);
            
            int rT;
            if(dp[k+1][j][1]!=-1)  
                rT = dp[k+1][j][1];
            else
                rT = rec(s,k+1,j,true);
            
            int rF;
            if(dp[k+1][j][0]!=-1)
                rF = dp[k+1][j][0];
            else  
                rF = rec(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(istrue){
                    ans+=(lT*rT);
                    dp[i][j][istrue] = ans;
                }else{
                    ans+=(lT*rF+lF*rT+rF*lF);
                    dp[i][j][istrue] = ans;
                }
            }else if(s[k]=='|'){
                if(istrue){
                    ans+=(lT*rF+lF*rT+lT*rT);
                    dp[i][j][istrue] = ans;
                }else{
                    ans+=(lF*rF);
                    dp[i][j][istrue] = ans;
                }
            }else if(s[k]=='^'){
                if(istrue){
                    ans+=(lF*rT+lT*rF);
                    dp[i][j][istrue] = ans;
                }else{
                    ans+=(lT*rT+lF*rF);
                    dp[i][j][istrue] = ans;
                }
            }
            // cout<<ans<<endl;
        }return dp[i][j][istrue] = ans%1003;
    }


    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return rec(S,0,N-1,true);
    }
};
/****************************************************************************************/

// Egg Dropping Puzzle  - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int f, int e, vector<vector<int>> &dp){
        if(f == 0 || f == 1)
            return f;
        if(e == 1)
            return f;
        if(dp[e][f] != -1)
            return dp[e][f];
        int res = INT_MAX;
        for(int k = 1; k<=f; k++){
            int tempRes = 1 + max(solve(k-1, e-1, dp), solve(f-k, e, dp));
            res = min(res, tempRes);
        }
        dp[e][f] = res;
        return dp[e][f];
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>> dp(e+1, vector<int> (f+1, -1));
        return solve(f, e, dp);
        
    }
};
/********************************************************************************************/

// Longest Common Subsequence - https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        // your code here
        // vector<vector<int>> dp(y, vector<int> (x, -1));
        int dp[x+1][y+1];
        for(int i = 0; i<=x; i++)
            dp[i][0] = 0;
        for(int j = 0; j<=y; j++)
            dp[0][j] = 0;
        for(int i = 1; i<=x; i++){
            for(int j = 1; j<=y; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];

    }
};
/*********************************************************************************************/
// Longest Common Substring  - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
class Solution{
    public:
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        // your code here
        int res = 0;
        int dp[x+1][y+1];
        for(int i = 0; i<=x; i++)
            dp[i][0] = 0;
        for(int j = 0; j<=y; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i<=x; i++){
            for(int j = 1; j<=y; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return res;
    }
};

/***************************************************************************************************************/
// Print all LCS sequences  - https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1#
class Solution
{
	int dp[101][101];
	int lcs_len = 0;
	vector<string> res;
	private:
		int lcs(string s, string t, int pos1, int pos2)
		{
			// base condition 
			if(pos1 == s.size() or pos2 == t.size())
				return 0;
			int &ans  = dp[pos1][pos2];
			// if lcs has been computed
			if(ans != -1)
				return ans;
			// if characters are same return previous + 1 else 
			// max of two sequences after removing i'th and j'th 
			// char one by one 
			if(s[pos1] == t[pos2])
				return ans = 1 + lcs(s, t, pos1 + 1, pos2 + 1);
			return ans = max(lcs(s, t, pos1 + 1, pos2), lcs(s, t, pos1, pos2 + 1));
		}
	private:
		void helper(string s, string t, string cur, int pos1, int pos2, int cur_lcs)
		{
			// if currlcs is equal to lcslen then store it 
			if(cur_lcs == lcs_len)
			{
				res.push_back(cur);
				return ;
			}
			// if we are done with all the characters of both string 
			if(pos1 == s.size() or pos2 == t.size())
				return ;
		    // here we have to print all sub-sequences lexicographically, 
    		// that's why we start from 'a'to'z' if this character is 
    		// present in both of them then append it in cur and same 
    		// remaining part 
			for(char ch = 'a'; ch <= 'z'; ch++)
			{
				// f is a flag to tell that we have printed all the 
        		// subsequences corresponding to current character
				bool f = false;
				for(int i = pos1; i < s.size(); i++)
				{
					if(s[i] == ch)
					{
						for(int j = pos2; j < t.size(); j++)
						{
		                // if ch is present in both of them and 
                		// remaining length is equal to remaining 
                		// lcs length then add ch in sub-sequenece 
							if(t[j] == ch and lcs(s, t, i, j) == lcs_len - cur_lcs)
							{
								string new_cur = cur + ch;
								helper(s, t, new_cur, i + 1, j + 1, cur_lcs + 1);
								f = true;
								break;
							}
						}
					}
					// If we found LCS beginning with current character
					if(f)
						break;
				}
			}
		}
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
			memset(dp, -1, sizeof(dp));
			// Find lcs_length
			lcs_len = lcs(s, t, 0, 0);
			// function to get all longest common subsequences
			helper(s, t, "", 0, 0, 0);
			return res;
		}
};

/**********************************************************************************************/
// Shortest Common Supersequence  - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(int x, int y, string s1, string s2){
        // your code here
        // vector<vector<int>> dp(y, vector<int> (x, -1));
        int dp[x+1][y+1];
        for(int i = 0; i<=x; i++)
            dp[i][0] = 0;
        for(int j = 0; j<=y; j++)
            dp[0][j] = 0;
        for(int i = 1; i<=x; i++){
            for(int j = 1; j<=y; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int l = lcs(m, n, X, Y);
        return max(m, n) + min(m, n) - l; 
        // or resturn m + n - l;
    }
};
/******************************************************************************************************/
// Minimum number of deletions and insertions.  - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
class Solution{
	public:
	int lcs(int x, int y, string s1, string s2){
        // your code here
        // vector<vector<int>> dp(y, vector<int> (x, -1));
        int dp[x+1][y+1];
        for(int i = 0; i<=x; i++)
            dp[i][0] = 0;
        for(int j = 0; j<=y; j++)
            dp[0][j] = 0;
        for(int i = 1; i<=x; i++){
            for(int j = 1; j<=y; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int x = str1.length();
	    int y = str2.length();
	    int l = lcs(x, y, str1, str2);
	    int res = x - l + y - l;
	    return res;
	} 
};
/*******************************************************************************************/
// Longest Palindromic Subsequence - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

    int lcs(int x, int y, string s1, string s2){
            // your code here
            // vector<vector<int>> dp(y, vector<int> (x, -1));
            int dp[x+1][y+1];
            for(int i = 0; i<=x; i++)
                dp[i][0] = 0;
            for(int j = 0; j<=y; j++)
                dp[0][j] = 0;
            for(int i = 1; i<=x; i++){
                for(int j = 1; j<=y; j++){
                    if(s1[i-1] == s2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            return dp[x][y];
        }
    int longestPalinSubseq (string s2){
        // your code here
        int n = s2.length();
        string s1 = s2;
        reverse(s2.begin(), s2.end());
        return lcs(n, n, s1, s2);
    }
/************************************************************************************************/
// Minimum number of deletions. - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

int lcs(int x, int y, string s1, string s2){
            // your code here
            // vector<vector<int>> dp(y, vector<int> (x, -1));
            int dp[x+1][y+1];
            for(int i = 0; i<=x; i++)
                dp[i][0] = 0;
            for(int j = 0; j<=y; j++)
                dp[0][j] = 0;
            for(int i = 1; i<=x; i++){
                for(int j = 1; j<=y; j++){
                    if(s1[i-1] == s2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            return dp[x][y];
        }
    int longestPalinSubseq (string s2){
        // your code here
        int n = s2.length();
        string s1 = s2;
        reverse(s2.begin(), s2.end());
        return lcs(n, n, s1, s2);
    }
    int minDeletions(string str, int n) { 
        //complete the function here 
        return n - longestPalinSubseq(str);
    } 
/*****************************************************************************************************/
// Longest Repeating Subsequence - https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    string s1 = str;
		    string s2 = str;
		    int dp[n+1][n+1];
            for(int i = 0; i<=n; i++)
                dp[i][0] = 0;
            for(int j = 0; j<=n; j++)
                dp[0][j] = 0;
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    if(s1[i-1] == s2[j-1] && i != j)
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            return dp[n][n];
		}

};

/*************************************************************************************************/
// Wildcard Pattern Matching  - https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1#

int wildCard(string pattern,string str){
        int m=pattern.size();
        int n=str.size();
        
        bool dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;            //if both string and pattern are empty
        
        for(int i=1;i<=m;i++){
           if(pattern[i-1]=='*')  //if pattern starts with '*' 
           dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
                else if(pattern[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
/*******************************************************************************************/
// Form a palindrome - https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1#

class Solution{
    public:
    int lcs(int x, int y, string s1, string s2){
        int dp[x+1][y+1];
        for(int i = 0; i<=x; i++)
            dp[i][0] = 0;
        for(int j = 0; j<=y; j++)
            dp[0][j] = 0;
        for(int i = 1; i<=x; i++){
            for(int j = 1; j<=y; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
    int longestPalinSubseq (string s2){
        // your code here
        int n = s2.length();
        string s1 = s2;
        reverse(s2.begin(), s2.end());
        return lcs(n, n, s1, s2);
    }
    int countMin(string str){
    //complete the function here
        int n = str.length();
        return n - longestPalinSubseq(str);
    }
};
/*****************************************************************************************/
// Word Break - https://practice.geeksforgeeks.org/problems/word-break1352/1#

class Solution
{
public:
    bool solve(string str, int i, int j, vector<string> v){
        
        if(i>j)
            return true;
        for(int k = i; k<=j; k++){
            string s = str.substr(i, k - i + 1);
            if (std::find(v.begin(), v.end(), s) != v.end()){
               if(solve(str, k+1, j, v))
                    return true;
            }
        }
        return false;
    }
    int wordBreak(string a, vector<string> &v) {
        //code here
        int n = a.length();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(a, 0, n-1, v);
    }
};
/****************************************************************************************/
// Subset Sum Problem  - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
      int dp[n+1][sum+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i<=sum; i++)
            dp[0][i] = 0;
        for(int i = 0; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};
/*****************************************************************************************/

// Partition Equal Subset Sum - https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

class Solution{
public:
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        int dp[n+1][sum+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i<=sum; i++)
            dp[0][i] = 0;
        for(int i = 0; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int n, int arr[]){
        // code here
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += arr[i];
        if(sum % 2 == 0)
            return isSubsetSum(n, arr, sum/2);
        return 0;
    }
};
/****************************************************************************************/

// Perfect Sum Problem  - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
class Solution{
	public:
	int perfectSum(int arr[], int n, int sum){
        // Your code goes here
        int dp[n+1][sum+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i<=sum; i++)
            dp[0][i] = 0;
        for(int i = 0; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j - arr[i-1]] % 1000000007 + dp[i-1][j] % 1000000007) % 1000000007;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
	}
	  
};
/*********************************************************************************************/

// Minimum sum partition  - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        for(int i = 0; i<n; i++)
            sum += arr[i];
	    int dp[n+1][sum+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i<=sum; i++)
            dp[0][i] = 0;
        for(int i = 0; i<=n; i++)
            dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        vector<int> v;
        for(int i = 0; i<=sum/2; i++){
            if(dp[n][i])
                v.push_back(i);
        }
        int res = INT_MAX;
        for(int i = 0; i<v.size(); i++)
            res = min(res, sum - 2*v[i]);
        return res;
	} 
};
/**************************************************************************************/
// Interleaved Strings  - https://practice.geeksforgeeks.org/problems/interleaved-strings/1#

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(string a, string b, string c, int n, int m, int l){
        if(l == 0)
            return true;
        if(n == 0 && m == 0)
            return false;
        bool val1 = false; bool val2 = false;
        if(n > 0 && c[l - 1] == a[n - 1])
            val1 = solve(a, b, c, n - 1, m, l - 1);
        if(m > 0 && c[l - 1] == b[m - 1])
            val2 = solve(a, b, c, n, m - 1, l - 1);
        if(val1 || val2)
            return true;
        return false;
    }
    bool isInterleave(string a, string b, string c) {
        int l = c.length();
        int n = a.length();
        int m = b.length();
        return solve(a, b, c, n, m, l);
    }

};
/*******************************************************************************/
// Maximum Profit  - https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here
        int dp[k+1][n];
        for(int i = 0; i<=k; i++)
            for(int j = 0; j<n; j++)
                dp[i][j] = 0;
        for(int i = 1; i<=k; i++){
            int maxBuy = INT_MIN;
            for(int j = 1; j<n; j++){
                maxBuy = max(maxBuy, dp[i-1][j-1] - A[j-1]);
                dp[i][j] = max(dp[i][j-1], maxBuy + A[j]);
            }
        }
        return dp[k][n-1];
    }
};
/********************************************************************************/
// Maximum sum Rectangle  - https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#

class Solution {
  public:
     int kadane(int arr[], int n){
        int res = arr[0];
    
        int maxEnding = arr[0];
    
        for (int i = 1; i < n; i++){
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(maxEnding, res);
        }
        return res;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int res = INT_MIN;
        for(int k = 0; k<R; k++){
            int arr[C] = {0};
            for(int i = k; i<R; i++){
                for(int j = 0; j<C; j++){
                    arr[j] += M[i][j];
                }
                int subres = kadane(arr, C);
                res = max(res, subres);
            }
        }
        return res;
    }
};
/**********************************************************************************************/
// Mobile numeric keypad  - https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution{


	public:
	long long dp[10][26];

	long long ref[4][3] = { {1, 2, 3},
                    		    {4, 5, 6},
                    		    {7, 8, 9},
                    		    {-1, 0, -1}
		                      };
	long long solve(int i, int j, int n){
	    if(ref[i][j] == -1)
	        return 0;
	    if(n == 1)
	        return 1;
	    if(dp[ref[i][j]][n] != -1)
	        return dp[ref[i][j]][n];
	    long long a = solve(i, j, n-1);
	    long long b, c, d, e;
	    b = 0, c = 0, d = 0, e = 0;
	    if(j - 1 >= 0 && ref[i][j-1] != -1)
	        b = solve(i, j - 1, n - 1);
	    if(j + 1 < 3 && ref[i][j+1] != -1)
	        c = solve(i, j + 1, n - 1);
	    if(i - 1 >= 0 && ref[i-1][j] != -1)
	        d = solve(i - 1, j, n - 1);
	    if(i + 1 < 4 && ref[i+1][j] != -1)
	        e = solve(i + 1, j, n - 1);
	    return dp[ref[i][j]][n] = a + b + c + d + e;
	}
	long long getCount(int n)
	{
		// Your code goes here
		
// 		vector<vector<int>> dp(10, vector<int> (n+1, -1));
dp[10][N+1];
memset(dp, -1, sizeof(dp));
		long long res = 0;
		for(int i = 0; i<4; i++){
		    for(int j = 0; j<3; j++){
		        res += solve(i, j, n, dp);
		    }
		}
        return res;
	}


};
/********************************************************************************************/
// Word Wrap - https://practice.geeksforgeeks.org/problems/word-wrap1646/1#
class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        int space[n+1][n+1];
        int cost[n+1][n+1];
        for(int i = 1; i<=n; i++){
            space[i][i] = k - nums[i-1];
            for(int j = i+1; j<=n; j++){
                space[i][j] = space[i][j-1] - nums[j-1] - 1;
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(space[i][j] < 0){
                    space[i][j] = INT_MAX;
                    cost[i][j] = INT_MAX;
                }
                else if(j == n && space[i][j] >= 0){
                    space[i][j] = 0;
                    cost[i][j] = 0;
                }
                else{
                    cost[i][j] = space[i][j] * space[i][j];
                }
            }
        }
        int c[n+1];
        c[0] = 0;
        for(int i = 1; i<=n; i++){
            c[i] = INT_MAX;
            for(int j = 1; j<=i; j++){
                if(c[j - 1] != INT_MAX && cost[j][i] != INT_MAX)
                    c[i] = min(c[i], c[j-1] + cost[j][i]);
            }
        }
        return c[n];
    } 
};
/********************************************************************************************************************/
// Optimal Strategy For A Game  - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

long long maximumAmount(int arr[], int n) 
{
    long long dp[n][n];
    for(int i = 0; i<n-1; i++)
        dp[i][i+1] = max(arr[i], arr[i+1]);
    for(int gap = 3; gap<n; gap += 2){
        for(int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), arr[j] + min(dp[i][j-2], dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}

/******************************************************************************************************************/
// Count Derangements- https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
// A Naive Recursive C++ program
// to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
// Base cases
if (n == 1) return 0;
if (n == 2) return 1;

// countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

// Driver Code
int main()
{
	int n = 4;
	cout << "Count of Derangements is "
		<< countDer(n);
	return 0;
}

// DP 

class Solution{
public:
    long int disarrange(int n){
        // code here
        long long int dp[n+1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i<=n; i++)
            dp[i] = (i - 1) * (dp[i-1]%1000000007 + dp[i-2]%1000000007)%1000000007;
        return dp[n];

    }
};
/************************************************************************************/
// Longest Increasing Subsequence  - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#
// O(n^2)
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n];
       int res = INT_MIN;
       for(int i = 0; i<n; i++){
           int maxm = 0;
           for(int j = 0; j<i; j++){
               if(a[j] < a[i])
                    maxm = max(maxm, dp[j]);
           }
           dp[i] = maxm + 1;
           res = max(res, dp[i]);
       }
       return res;
    }
};
// O(nlog(n))
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]){
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[idx] = min(dp[idx], a[i]);
        }
        
        int ans = 0;
        
        for (int i = n; i >= 0; --i) {
            if (dp[i] != INT_MAX) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
/*************************************************************************************************/
// Longest alternating subsequence  - https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&a){
		    // Code here
		    int n = a.size();
		    int inc = 1;
		    int dec = 1;
		    for(int i = 1; i<n; i++){
		        if(a[i] > a[i-1])
		            inc = dec+1;
		        else if(a[i] < a[i-1])
		            dec = inc + 1;
		    }
		    return max(inc, dec);
		}

};
/***************************************************************************************************/
// Count Palindromic Subsequences - https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#

class Solution{
    public:
        long long int dp[1001][1001];
        int mod = 1e9+7;
    long long int solve(string &x,int i,int j){
        if(i>j) 
            return 0;
        if(i==j) return 
            1;
        if(dp[i][j]!=-1) 
            return dp[i][j];
    
        if(x[i]==x[j]){
            dp[i][j] = (1%mod+solve(x,i+1,j)%mod+solve(x,i,j-1)%mod)%mod;
            return dp[i][j]%mod;
        }
        // (a-b)%mod = (a%mod-b%mod+mod)%mod; -> to avoid modulus of negative //values
        else{
            dp[i][j]=(solve(x,i+1,j)%mod+solve(x,i,j-1)%mod-solve(x,i+1,j-1)%mod+mod)%mod;
            return dp[i][j]%mod;
        }
    }
    long long int countPS(string str){
    //Your code here
        memset(dp,-1,sizeof(dp));
    
        return solve(str,0,str.size()-1);
    }
};
/**********************************************************************************************************/
// Reach a given score - https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1#
// (same as coin change - count combinations)
long long int count(long long int n)
{
	long long int dp[4][n+1];
	memset(dp, 0, sizeof(dp));
    int val[3] = {3, 5, 10};
    for(int i = 0; i<=3;i++)
        dp[i][0] = 1;
    for(int i = 0; i<=n; i++)
        dp[0][i] = 0;
    for(int i = 1; i<=3; i++){
        for(int j = 1; j<=n; j++){
            if(val[i-1]<=j)
                dp[i][j] = dp[i][j-val[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[3][n];
}
/****************************************************************************/
// Gold Mine Problem - https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int j = m-1; j>=0; j--){
            for(int i = 0; i<n; i++){
                if(j == m-1)
                    dp[i][j] = M[i][j];
                else if(i == 0)
                    dp[i][j] = M[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
                else if(i == n-1)
                    dp[i][j] = M[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
                else
                    dp[i][j] = M[i][j] + max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1]));
            }
        }
        int res = INT_MIN;
        for(int i = 0; i<n; i++)
            res = max(res, dp[i][0]);
        return res;
    }
};
/*************************************************************************************/
// LCS of three strings  - https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

int LCSof3(string s1, string s2, string s3, int x, int y, int z)
{
    // your code here
        int dp[x+1][y+1][z+1];
        for(int i = 0; i<=x; i++){
            for(int j = 0; j<=y; j++){
                for(int k = 0; k<=z; k++){
                    if(i == 0 || j == 0 || k == 0)
                        dp[i][j][k] = 0;
                    else{
                        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                            dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                        else
                            dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                    }
                }
            }
        }
        return dp[x][y][z];
}
/******************************************************************************************/
// Maximum sum increasing subsequence  - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int res = INT_MIN;
	    int dp[n] = {0};
	    for(int i = 0; i<n; i++){
	        int maxSoFar = 0;
	        for(int j = 0; j<i; j++){
	            if(arr[i] > arr[j])
	                maxSoFar = max(maxSoFar, dp[j]);
	        }
	        dp[i] = arr[i] + maxSoFar;
	        res = max(res, dp[i]);
	    }
	    return res;
	}  
};

/**********************************************************************************************/
// Longest subsequence-1  - https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
       int dp[n];
       int res = INT_MIN;
       for(int i = 0; i<n; i++){
           int maxm = 0;
           for(int j = 0; j<i; j++){
               if(abs(a[j] - a[i]) == 1)
                    maxm = max(maxm, dp[j]);
           }
           dp[i] = maxm + 1;
           res = max(res, dp[i]);
       }
       return res;
    }
};
/**********************************************************************************************/
// Max length chain  - https://practice.geeksforgeeks.org/problems/max-length-chain/1#
/*
    Sort the given range according the first value.

    Fill the dp array accordingly
    for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(p[i].first>p[j].second and dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
        
*/
static bool compare(struct val a, struct val b){
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n){
//Your code here
    sort(p, p+n, compare);
    int dp[n] = {0};
    int res = INT_MIN;
    for(int i = 0; i<n; i++){
        int maxSoFar = 0;
        for(int j = 0; j<i; j++){
            if(p[j].second < p[i].first)
                maxSoFar = max(maxSoFar, dp[j]);
        }
        dp[i] = maxSoFar + 1;
        res = max(res, dp[i]);
    }
    return res;
}
/**************************************************************************************/
// Pairs with specific difference  - https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#
/*
First we sort the given array in increasing order. Once array is sorted, we traverse the array. For every element, we try to pair it with its previous element first. Why do we prefer previous element? Let arr[i] can be paired with arr[i-1] and arr[i-2] (i.e. arr[i] – arr[i-1] < K and arr[i]-arr[i-2] < K). Since the array is sorted, value of arr[i-1] would be more than arr[i-2]. Also, we need to pair with difference less than k, it means if arr[i-2] can be paired, then arr[i-1] can also be paired in a sorted array.
Now observing the above facts, we can formulate our dynamic programming solution as below,
Let dp[i] denotes the maximum disjoint pair sum we can achieve using first i elements of the array. Assume currently we are at i’th position, then there are two possibilities for us.

  Pair up i with (i-1)th element, i.e. 
      dp[i] = dp[i-2] + arr[i] + arr[i-1]
  Don't pair up, i.e. 
      dp[i] = dp[i-1] 
Above iteration takes O(N) time and sorting of array will take O(N log N) time so total time complexity of the solution will be O(N log N)
*/
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr, arr+n);
        int dp[n+1] = {0};
        for(int i = 2; i<=n; i++){
            if(arr[i-1] - arr[i-2] < k)
                dp[i] = dp[i-2] + arr[i-1] + arr[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[n];        
    }
};
/************************************************************************************/
// Maximum path sum in matrix  - https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> m){
        // code here
        if(n == 1)
            return m[0][0];
        int dp[n][n];
        for(int j = 0; j<n; j++)
            dp[n-1][j] = m[n-1][j];
        int res = INT_MIN;
        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(j == 0){
                    dp[i][j] = m[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
                }
                else if(j == n-1)
                    dp[i][j] = m[i][j] + max(dp[i+1][j-1], dp[i+1][j]);
                else
                    dp[i][j] = m[i][j] + max(dp[i+1][j-1], max(dp[i+1][j],dp[i+1][j+1]));
                if(i == 0)
                    res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
/*******************************************************************************/
// Maximum difference of zeros and ones in binary string - https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
/*
1. Assume o as 1 and 1 as -1, then apply Kadane’s algorithm
or 
Use DP
2. dp[i] stores the maxm diff if the string ends at element s[i]
*/
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    int dp[n];
	    int res = INT_MIN;
	    if(s[0] == '1')
            dp[0] = -1;
        else
            dp[0] = 1;
        res = dp[0];
	    for(int i = 1; i<n; i++){
	        if(s[i] == '0')
	            dp[i] = max(1+dp[i-1], 1);
	        else
	            dp[i] = max(dp[i-1] - 1, -1);
	        res = max(res, dp[i]);
	    }
	    return res;
	}
};