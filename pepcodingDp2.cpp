// count Palindromic Subsequences

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        int dp[n];
        for(int gap = 0; gap<n; gap++){
            for(int i = 0, j = gap; j<n; i++, j++){
                if(gap == 0)
                    dp[i][j] = 1;
                else if(gap == 1){
                    if(s[0] == s[1])
                        dp[i][j] = 3;
                    else
                        dp[i][j] = 2;
                }
                else{
                    if(s[i] == s[j])
                        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                    else
                        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
            }
        }
        return dp[0][n - 1];
    }
};