class Solution {
public:
    int memo[20000][26];
    int dp(int i, char lastChar, int n, string str){
        if(i == n)
            return 1;
        int lastCharInt = lastChar - 'a';
        if(memo[i][lastCharInt] != 0)
            return memo[i][lastCharInt];
        // memo[i][lastCharInt] = 0;
        if(lastChar == 'z'){
            for(auto s : str)
                memo[i][lastCharInt] = (memo[i][lastCharInt] + dp(i + 1, s, n, str)%1000000007)%1000000007;
        }
        if(lastChar == 'a')
            memo[i][lastCharInt] = dp(i + 1, 'e', n, str);
        if(lastChar == 'e')
            memo[i][lastCharInt] = (dp(i + 1, 'a', n, str) %1000000007 + dp(i + 1, 'i', n, str)%1000000007)%1000000007;
        if(lastChar == 'i')
            for(auto s : str)
                if(s != lastChar)
                    memo[i][lastCharInt] = (memo[i][lastCharInt] + dp(i + 1, s, n, str)%1000000007)%1000000007;
        if(lastChar == 'o')
            memo[i][lastCharInt] = (dp(i + 1, 'i', n, str)%1000000007 + dp(i + 1, 'u', n, str)%1000000007)%1000000007;
        if(lastChar == 'u')
            memo[i][lastCharInt] = dp(i + 1, 'a', n, str);

        return memo[i][lastCharInt]%1000000007;
    }
    int countVowelPermutation(int n){
        memset(memo, 0, sizeof(memo));
        string str = "aeiou";
        int res = dp(0, 'z', n, str);
        return res;
    }
};