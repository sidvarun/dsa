https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 2, 0);
        dp[n] = 1;
        for(int i = n - 1; i>=0; i--){
             int n1 = s[i] - '0';
            int n2 = s[i + 1] - '0';
            if(n1 == 0)
                dp[i] =  0;
            else{
                int num = 10*n1 + n2;
                if(n1 != 0 && num <= 26)
                    dp[i]  = dp[i + 1] + dp[i + 2];
                else
                    dp[i] = dp[i + 1];               
            }
        }
        return dp[0];
    }
};
