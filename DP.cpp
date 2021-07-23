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