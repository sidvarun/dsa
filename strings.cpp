// Reverse the string
void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        int mid = (i+j)/2;
        while(i<j){
            char temp = s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        for(auto x:s)
            cout<<x<<" ";
        
    }

//palindrome string
int isPlaindrome(string s)
	{
	    // Your code goes here
	    int i = 0;
	    int j = s.length()-1;
	    while(i<j){
	        if(s[i]!=s[j])
	            return 0;
	        i++;
	        j--;
	    }
	    return 1;
	}
/////////////////////////////////////////////////////////////////////////////////////////
// Longest Palindromic sunbstring in a string
int lenOfPalindrome(string s, int left, int right){
    if(left>right)
      return 0;
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalin (string s)
{
    // your code here
    int l1,l2,l = 0;
    int res = INT_MIN;
    if(s.length()<1)
     return "";
    int start = 0;
    int end = 0;
    for(int i=0; i<s.length(); i++){
        l1 = lenOfPalindrome(s,i,i);
        l2 = lenOfPalindrome(s,i,i+1);
        int l = max(l1,l2);
        if(l>end - start){
            // res = l;
            start = i - (l-1)/2;
            end = i + l/2;
        }
    }
    return s.substr(start, end+1);
}

// edit distance problem
// Recursive code
class Solution {
  public:
    int editDistUtil(string s, string t, int i, int j){
        if(i==0)
            return j;
        if(j==0) 
            return i;
        if(s[i-1]==t[j-1])
            return editDistUtil(s,t,i-1,j-1);
        else
            return 1+min(editDistUtil(s,t,i,j-1),min(editDistUtil(s,t,i-1,j),editDistUtil(s,t,i-1,j-1)));
    }
    int editDistance(string s, string t) {
        // Code here
        return editDistUtil(s,t,s.length(),t.length());
    }
};

// using DP
class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size();
    int m = t.size();
    int dp[n+1][m+1];
    for(int i = 0 ; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] =1 + min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
        }
    }
    return dp[n][m];
    }
};
// Word Wrap 
class Solution {
public:
vector<vector<int>> solveWordWrap(vector<int>nums, int k) 
{ 
    // Code here
    vector<vector<int>> v;
    vector<int> subRes;
    int sum,temp = 0;
    int start = 0;
    int end = -1;
    for(auto i = 0; i<nums.size();){
        while(true){
            sum = sum + nums[i]+1;
            if(sum<=k){
                end++;
                i++;
            }
            else if(sum>k){
                subRes.push_back(start+1);
                subRes.push_back(end+1);
                v.push_back(subRes);
                start = end + 1;
                sum = 0;
                i=start;
                break;
            }
        }
    }
    return v;
} 
};

// Roman Number to integer
// Without using extra space
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}
int romanToDecimal(string &str) {
    // Initialize result
    int res = 0;

    // Traverse given input
    for (int i = 0; i < str.length(); i++) 
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i + 1 < str.length()) 
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);

            // Comparing both values
            if (s1 >= s2) 
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}
// using extra space
// Program to convert Roman
// Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// This function returns value
// of a Roman symbol
int romanToDecimal(string& str)
{
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[i + 1]])
        {
            sum+=m[str[i+1]]-m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}
// generate all the subsequences of the given string 
// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences of a given string 
void printSubsequence(string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist characther of
	// Input string
	printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence(input.substr(1), output);
}

// Driver code
int main()
{
	// output is set to null before passing in as a
	// parameter
	string output = "";
	string input = "abcd";

	printSubsequence(input, output);

	return 0;
}
//////////////////////////////////////////
//Next lexicographic permutation
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        // code here
        int i;
        for(i=n-2; i>=0; i--){
            if(a[i]<a[i+1]){
                break;
            }
        }
        
        if(i<0)
            reverse(a.begin(),a.end());
        else{
            int it;
            for(it = n-1; it>i; it--){
                if(a[it]>a[i]){
                    break;
                }
            }
            swap(a[i],a[it]);
            reverse(a.begin() + i +1, a.end());
        }
        return a;
    }
};
/*********************************************************************/
//Longest Common Subsequence 
// Recursive
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcsUtil(int i, int j, string s1, string s2, int res){
        if(i==0 || j==0)
            return res;
        if(s1[i-1]==s2[j-1])
            res =  1 + lcsUtil(i-1,j-1,s1,s2,res);
        else if (s1[i-1]!=s2[j-1])
            res = max(lcsUtil(i-1,j,s1,s2,res),lcsUtil(i,j-1,s1,s2,res));
        return res;
        
    }
    

    int lcs(int i, int j, string s1, string s2)
    {
        // your code here
        int res = 0;
        return lcsUtil(i,j,s1,s2,res);
    }
};

// DP solution
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings
    

    int lcs(int x, int y, string s1, string s2)
    {
        
    // your code here
        int dp[x+1][y+1];
        for(int i = 0; i <= x; i++)
            dp[i][0] = 0;
            
        for(int j = 0; j <= y; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};

