class Solution {
public:
    int memo[101][101];
    bool dp(int i, int j, int k, string s1, string s2, string s3){
        if(i == s1.length())
            return s3.substr(k) == s2.substr(j);
        if(j == s2.length())
            return s3.substr(k) == s1.substr(i);
        if(memo[i][j] != -1)
            return memo[i][j] == 1 ? true : false;
        bool ans = false;
        if(s1[i] == s3[k])
            ans |= dp(i + 1, j, k + 1, s1, s2, s3);
        if(s2[j] == s3[k])
            ans |= dp(i, j + 1, k + 1, s1, s2, s3);
        memo[i][j] = ans == true ? 1 : 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0, s1, s2, s3);
    }
};