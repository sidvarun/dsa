class Solution {
public:
    int dp(int i, string s){
        if(i == s.length())
            return 1;
        if(i > s.length())
            return 0;
        if(memo[i] != -1)
            return memo[i];
        int digit1 = s[i] - '0';
        int digit2 = s[i + 1] - '0';
        int num = digit1 * 10 + digit2;
        if(digit1 == 0)
            memo[i] = 0;
        else if(num >= 1 && num <= 26)
            memo[i] = dp(i + 1, s) + dp(i + 2, s);
        else
            memo[i] = dp(i + 1, s);
        return memo[i];
    }
    int memo[100];
    int numDecodings(string s) {
        memset(memo, -1, sizeof(memo));
        return dp(0, s);
    }
};